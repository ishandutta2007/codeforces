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
char s[1010][1010];
int fa[2010];
il int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
std::vector<int>G[2010];
int ans[2010],cnt,in[2010];
int now[2010],k;
int main(){
	int n=gi(),m=gi();
	for(int i=1;i<=n+m;++i)fa[i]=i;
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;++j)if(s[i][j]=='=')fa[hd(i)]=hd(n+j);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			int A=hd(i),B=hd(n+j);
			if(s[i][j]=='=');
			else{
				if(A==B)return puts("No"),0;
				if(s[i][j]=='>')G[B].push_back(A),++in[A];
				else G[A].push_back(B),++in[B];
			}
		}
	while(1){
		k=0;
		for(int i=1;i<=n+m;++i)if(fa[i]==i&&!in[i])now[++k]=i;
		if(!k)break;
		++cnt;
		for(int i=1;i<=k;++i){
			ans[now[i]]=cnt;
			for(int j=0;j<G[now[i]].size();++j)--in[G[now[i]][j]];
			in[now[i]]=-1;
		}
	}
	for(int i=1;i<=n+m;++i)if(fa[i]==i&&!ans[i])return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=n;++i)printf("%d ",ans[fa[i]]);puts("");
	for(int i=n+1;i<=n+m;++i)printf("%d ",ans[fa[i]]);puts("");
	return 0;
}