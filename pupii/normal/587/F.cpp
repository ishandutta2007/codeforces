#include<bits/stdc++.h>
#define B 320
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char S[100010];
int n,q,cnt,ch[100010][26],fail[100010],len[100010],node[100010];
int qL[100010],qR[100010];
ll ans[100010];
std::vector<int>qq[100010],nodes[100010],qaq[100010],son[100010];
int c[100010];
ll tm[100010];
int rt[100010],sum[10000010],ls[10000010],rs[10000010],SEG;
#define mid ((l+r)>>1)
void update(int&x,int l,int r,int p){
	sum[++SEG]=sum[x],ls[SEG]=ls[x],rs[SEG]=rs[x];
	++sum[x=SEG];if(l==r)return;
	if(p<=mid)update(ls[x],l,mid,p);
	else update(rs[x],mid+1,r,p);
}
int query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R)return sum[x];
	if(L<=mid)
		if(mid<R)return query(ls[x],l,mid,L,R)+query(rs[x],mid+1,r,L,R);
		else return query(ls[x],l,mid,L,R);
	else return query(rs[x],mid+1,r,L,R);
}
#undef mid
void dfs(int x){for(int i:son[x])dfs(i),c[x]+=c[i];}
void DFS(int x){
	for(int i:qaq[x])if(node[i]==x)update(rt[x],1,n,i);
	for(int i:qaq[x])
		if(len[i]<=B)
			for(int j:qq[i])
				ans[j]+=query(rt[x],1,n,qL[j],qR[j]);
	for(int i:son[x])rt[i]=rt[x],DFS(i);
}
std::queue<int>que;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),q=gi();
	int lens;
	for(int i=1;i<=n;++i){
		scanf("%s",S+1);lens=len[i]=strlen(S+1);
		int x=0;
		for(int j=1;j<=lens;++j){
			if(!ch[x][S[j]-'a'])ch[x][S[j]-'a']=++cnt;
			x=ch[x][S[j]-'a'];nodes[i].push_back(x);
		}
		node[i]=x;
	}
	for(int i=0;i<26;++i)if(ch[0][i])que.push(ch[0][i]);
	while(!que.empty()){
		int x=que.front();que.pop();
		for(int i=0;i<26;++i)
			if(ch[x][i]){
				fail[ch[x][i]]=ch[fail[x]][i];
				que.push(ch[x][i]);
			}else ch[x][i]=ch[fail[x]][i];
	}
	for(int i=1;i<=cnt;++i)son[fail[i]].push_back(i);
	for(int i=1;i<=q;++i)qL[i]=gi(),qR[i]=gi(),qq[gi()].push_back(i);
	for(int i=1;i<=n;++i){
		if(len[i]>B){
			memset(c,0,sizeof c);
			for(int j:nodes[i])++c[j];
			dfs(0);
			for(int j=1;j<=n;++j)tm[j]=tm[j-1]+c[node[j]];
			for(int j:qq[i])ans[j]=tm[qR[j]]-tm[qL[j]-1];
		}else for(int j:nodes[i])qaq[j].push_back(i);
	}
	DFS(0);
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
	return 0;
}