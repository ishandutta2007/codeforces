#include<bits/stdc++.h>
#define mod1 998244853
#define mod2 998244353
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m;
int pos(int x,int y){return(x-1)*m+y;}
std::string s[1000010];
int f1[1000010],g1[1000010];
int f2[1000010],g2[1000010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi();
	for(int i=1;i<=n;++i)std::cin>>s[i];
	f1[1]=f2[1]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(s[i][j-1]=='#')continue;
			if(i!=1)(f1[pos(i,j)]+=f1[pos(i-1,j)])%=mod1,(f2[pos(i,j)]+=f2[pos(i-1,j)])%=mod2;
			if(j!=1)(f1[pos(i,j)]+=f1[pos(i,j-1)])%=mod1,(f2[pos(i,j)]+=f2[pos(i,j-1)])%=mod2;
		}
	if(!f1[pos(n,m)]&&!f2[pos(n,m)])return puts("0"),0;
	g1[n*m]=g2[n*m]=1;
	for(int i=n;i;--i)
		for(int j=m;j;--j){
			if(s[i][j-1]=='#')continue;
			if(i<n)(g1[pos(i,j)]+=g1[pos(i+1,j)])%=mod1,(g2[pos(i,j)]+=g2[pos(i+1,j)])%=mod2;
			if(j<m)(g1[pos(i,j)]+=g1[pos(i,j+1)])%=mod1,(g2[pos(i,j)]+=g2[pos(i,j+1)])%=mod2;
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if((i!=1||j!=1)&&(i!=n||j!=m)&&1ll*f1[pos(i,j)]*g1[pos(i,j)]%mod1==f1[pos(n,m)]&&1ll*f2[pos(i,j)]*g2[pos(i,j)]%mod2==f2[pos(n,m)])return puts("1"),0;
	puts("2");
	return 0;
}