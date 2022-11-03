#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll ans=2;
struct SAM{
	int trans[200010][26],fa[200010],len[200010],cnt,lst;
	SAM(){cnt=lst=1;}
	int endpos[200010],leaf[200010];
	std::vector<int>G[200010];
	void extend(int c,int pos){
		int x=++cnt,p=lst;endpos[x]=pos,leaf[pos]=x,lst=x;len[x]=len[p]+1;
		while(p&&!trans[p][c])trans[p][c]=x,p=fa[p];
		if(!p)fa[x]=1;
		else{
			int q=trans[p][c];
			if(len[q]==len[p]+1)fa[x]=q;
			else{
				int nq=++cnt;memcpy(trans[nq],trans[q],4*26);
				len[nq]=len[p]+1;fa[nq]=fa[q];
				while(p&&trans[p][c]==q)trans[p][c]=nq,p=fa[p];
				fa[x]=fa[q]=nq;
			}
		}
	}
	void build(){for(int i=2;i<=cnt;++i)G[fa[i]].push_back(i);}
};
struct SAMB:SAM{
	int dfn[200010],rdfn[200010],top[200010],son[200010],dep[200010],siz[200010];
	void dfs(int x){
		siz[x]=1;dfn[x]=++dfn[0];rdfn[0]=x;
		for(int i:G[x]){
			dep[i]=dep[x]+1;dfs(i);
			siz[x]+=siz[i];
			if(siz[son[x]]<siz[i])son[x]=i;
		}
	}
	void dfs(int x,int tp){
		top[x]=tp;if(son[x])dfs(son[x],tp);
		for(int i:G[x])if(i!=son[x])dfs(i,i);
	}
	int LCA(int a,int b){
		while(top[a]^top[b])
			if(dep[top[a]]>dep[top[b]])a=fa[top[a]];
			else b=fa[top[b]];
		return dep[a]<dep[b]?a:b;
	}
	void pre(){
		for(int i=2;i<=cnt;++i)ans+=len[i]-len[fa[i]];
		dfs(1),dfs(1,1);
	}
}B;
struct Set{
	struct cmp{bool operator()(int a,int b){return B.dfn[a]<B.dfn[b];}};
	ll sum;std::set<int,cmp>S;
	void insert(int x){
		auto it=S.upper_bound(x);
		int pr=0,nx=0;
		if(it!=S.end())nx=*it;
		if(it!=S.begin())pr=*--it;
		sum+=B.len[x];
		if(pr)sum-=B.len[B.LCA(x,pr)];
		if(nx)sum-=B.len[B.LCA(x,nx)];
		if(pr&&nx)sum+=B.len[B.LCA(pr,nx)];
		S.insert(x);
	}
	void Union(Set&a){
		if(S.size()<a.S.size())std::swap(sum,a.sum),S.swap(a.S);
		for(int i:a.S)insert(i);
		a.sum=0,a.S.clear();
	}
};
struct SAMA:SAM{
	Set st[200010];
	void dfs(int x){
		if(endpos[x])st[x].insert(B.leaf[endpos[x]]);
		for(int i:G[x])dfs(i),st[x].Union(st[i]);
		if(x>1)ans+=1ll*(len[x]-len[fa[x]])*st[x].sum;
	}
	void pre(){
		for(int i=2;i<=cnt;++i)ans+=len[i]-len[fa[i]];
		dfs(1);
	}
}A;
char S[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",S+1);int n=strlen(S+1);
	for(int i=1;i<n;++i)A.extend(S[i]-'a',i<=n-2?i+1:0);
	A.pre();A.extend(S[n]-'a',0);
	for(int i=n;i>1;--i)B.extend(S[i]-'a',i>2?i-1:0);
	B.build(),B.pre(),A.build(),A.pre();
	printf("%lld\n",ans);
	return 0;
}