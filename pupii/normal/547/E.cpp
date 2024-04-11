#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char S[200010];
int slink[400010],trans[400010][26],len[400010],cnt=1,lst=1,node[200010];
void extend(int ch){
	if(trans[lst][ch]){
		int t=trans[lst][ch];
		if(len[t]==len[lst]+1)lst=t;
		else{
			int nt=++cnt,p=lst;memcpy(trans[nt],trans[t],4*26);
			slink[nt]=slink[t];len[nt]=len[p]+1;
			while(t&&trans[p][ch]==t)trans[p][ch]=nt,p=slink[p];
			slink[t]=nt;lst=nt;
		}
		return;
	}
	int x=++cnt,p=lst;lst=x;len[x]=len[p]+1;
	while(p&&!trans[p][ch])trans[p][ch]=x,p=slink[p];
	if(!p)slink[x]=1;
	else{
		int q=trans[p][ch];
		if(len[q]==len[p]+1)slink[x]=q;
		else{
			int nq=++cnt;memcpy(trans[nq],trans[q],4*26);
			slink[nq]=slink[q];len[nq]=len[p]+1;
			while(p&&trans[p][ch]==q)trans[p][ch]=nq,p=slink[p];
			slink[x]=slink[q]=nq;
		}
	}
}
int rt[400010],ls[10000010],rs[10000010],seg;
ll sum[10000010];
#define mid ((l+r)>>1)
void update(int&x,int l,int r,int p){
	if(!x)x=++seg;++sum[x];if(l==r)return;
	if(p<=mid)update(ls[x],l,mid,p);
	else update(rs[x],mid+1,r,p);
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	int r=++seg;
	sum[r]=sum[x]+sum[y];
	ls[r]=merge(ls[x],ls[y]);
	rs[r]=merge(rs[x],rs[y]);
	return r;
}
ll query(int x,int l,int r,int L,int R){
	if(!x||(L<=l&&r<=R))return sum[x];
	if(L<=mid)
		if(mid<R)return query(ls[x],l,mid,L,R)+query(rs[x],mid+1,r,L,R);
		else return query(ls[x],l,mid,L,R);
	else return query(rs[x],mid+1,r,L,R);
}
#undef mid
std::vector<int>G[400010];
void Merge(int x){
	for(int i:G[x])
		Merge(i),
			rt[x]=merge(rt[x],rt[i]);}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),q=gi(),l,r,k;
	for(int i=1;i<=n;++i){
		scanf("%s",S+1);
		int m=strlen(S+1);
		for(int j=1;j<=m;++j)extend(S[j]-'a'),update(rt[lst],1,n,i);
		node[i]=lst;lst=1;
	}
	for(int i=2;i<=cnt;++i)G[slink[i]].push_back(i);
	Merge(1);
	while(q--)l=gi(),r=gi(),k=gi(),printf("%d\n",query(rt[node[k]],1,n,l,r));
	return 0;
}