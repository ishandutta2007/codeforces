#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int fa[300010],ls[300010],rs[300010],ans[150010];
il int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
int lab=0;
il vd dfs(int x){
	if(!ls[x]){ans[++lab]=x;return;}
	dfs(ls[x]),dfs(rs[x]);
}
int main(){
	int n=gi();
	for(int i=1;i<=n<<1;++i)fa[i]=i;
	int cnt=n;
	for(int i=1;i<n;++i){
		int A=hd(gi()),B=hd(gi());
		fa[A]=fa[B]=++cnt;
		ls[cnt]=A,rs[cnt]=B;
	}
	dfs(cnt);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}