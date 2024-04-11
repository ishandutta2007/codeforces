#include<bits/stdc++.h>
#define maxn 1111111
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int m;
char S[500010];
int trans[maxn][26],slink[maxn],len[maxn],cnt=1,lst=1,leaf[500010];
int st[19][maxn];
std::vector<int>son[maxn];
void extend(int ch,int i){
	if(trans[lst][ch]){
		int p=lst,q=trans[lst][ch];
		if(len[q]==len[p]+1)lst=q;
		else{
			int nq=++cnt;len[nq]=len[p]+1;slink[nq]=slink[q];
			memcpy(trans[nq],trans[q],4*26);
			while(p&&trans[p][ch]==q)trans[p][ch]=nq,p=slink[p];
			slink[q]=lst=nq;
		}
		return;
	}
	int p=lst,x=++cnt;len[x]=len[p]+1,slink[x]=p;leaf[i]=x;
	while(p&&!trans[p][ch])trans[p][ch]=x,p=slink[p];
	if(!p)slink[x]=1;
	else{
		int q=trans[p][ch];
		if(len[q]==len[p]+1)slink[x]=q;
		else{
			int nq=++cnt;len[nq]=len[p]+1,slink[nq]=slink[q];
			memcpy(trans[nq],trans[q],4*26);
			while(p&&trans[p][ch]==q)trans[p][ch]=nq,p=slink[p];
			slink[x]=slink[q]=nq;
		}
	}
	lst=x;
}
struct data{int a,b;data(int _a=0,int _b=1e9){a=_a,b=_b;}}seg[30000010];
data operator+(const data&a,const data&b){
	if(a.b^b.b){
		if(a.a>b.a||(a.a==b.a&&a.b<b.b))return a;
		else return b;
	}
	return{a.a+b.a,a.b};
}
#define mid ((l+r)>>1)
int segcnt,ls[30000010],rs[30000010];
void update(int&x,int l,int r,int p){
	if(!x)x=++segcnt;if(l==r){++seg[x].a,seg[x].b=l;return;}
	if(p<=mid)update(ls[x],l,mid,p);
	else update(rs[x],mid+1,r,p);
	seg[x]=seg[ls[x]]+seg[rs[x]];
}
void merge(int&x,int y){
	if(!x||!y){if(!x)x=y;return;}
	if(!ls[x]&&!rs[x])seg[x]=seg[x]+seg[y];
	else{
		merge(ls[x],ls[y]);
		merge(rs[x],rs[y]);
		seg[x]=seg[ls[x]]+seg[rs[x]];
	}
}
data query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R)return seg[x];
	if(L<=mid)
		if(mid<R)return query(ls[x],l,mid,L,R)+query(rs[x],mid+1,r,L,R);
		else return query(ls[x],l,mid,L,R);
	else return query(rs[x],mid+1,r,L,R);
}
#undef mid
struct ques{int i,l,r;};
std::vector<ques>Q[maxn];
int rt[maxn];data ans[500010];
void Merge(int x){
	for(int i:son[x])Merge(i),merge(rt[x],rt[i]);
	for(auto[i,l,r]:Q[x]){
		ans[i]=query(rt[x],1,m,l,r);
		if(ans[i].a==0)ans[i].b=l;
	}
}
int main(){
	scanf("%s",S+1);
	int lens=strlen(S+1),n=lens;
	for(int i=1;i<=n;++i)extend(S[i]-'a',i);
	m=gi();
	for(int i=1;i<=m;++i){
		scanf("%s",S+1);lens=strlen(S+1);
		lst=1;for(int j=1;j<=lens;++j)extend(S[j]-'a',0),update(rt[lst],1,m,i);
	}
	for(int i=1;i<=cnt;++i)st[0][i]=slink[i];
	for(int i=1;i<19;++i)
		for(int j=1;j<=cnt;++j)
			st[i][j]=st[i-1][st[i-1][j]];
	for(int i=2;i<=cnt;++i)son[slink[i]].push_back(i);
	int q=gi(),l,r,L,R,x;
	for(int o=1;o<=q;++o){
		L=gi(),R=gi(),l=gi(),r=gi();
		x=leaf[r];for(int i=18;~i;--i)if(st[i][x]&&len[st[i][x]]>=r-l+1)x=st[i][x];
		Q[x].push_back({o,L,R});
	}
	Merge(1);
	for(int o=1;o<=q;++o){
		data q=ans[o];
		printf("%d %d\n",q.b,q.a);
	}
	return 0;
}