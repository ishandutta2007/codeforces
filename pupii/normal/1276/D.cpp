#include<bits/stdc++.h>
#define mod 998244353
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[200010][4];
std::vector<int>G[200010];
int son[200010],m,A[200010],B[200010],C[200010];
void add(int&a,int b){a=a+b>=mod?a+b-mod:a+b;}
void dfs(int x,int fa=-1){
	for(int i:G[x])if(fa!=i)dfs(i,x);
	m=0;int p=0;
	for(int i:G[x])
		if(fa==i)p=m;
		else{
			son[++m]=i;
			A[m]=(f[i][0]+f[i][1])%mod;
			B[m]=(f[i][2]+f[i][3])%mod;
			C[m]=(0ll+f[i][0]+f[i][2]+f[i][3])%mod;
		}
	if(!m){f[x][1]=f[x][3]=1;return;}
	A[0]=C[m+1]=1;
	for(int i=1;i<=m;++i)A[i]=1ll*A[i]*A[i-1]%mod;
	for(int i=m;i;--i)C[i]=1ll*C[i]*C[i+1]%mod;
	for(int i=1;i<=m;++i)add(f[x][(i>p)*2],1ll*A[i-1]*C[i+1]%mod*B[i]%mod);
	f[x][1]=1ll*A[p]*C[p+1]%mod;f[x][3]=A[m];
}
int main(){
	int n=gi(),u,v;
	for(int i=1;i<n;++i)u=gi(),v=gi(),G[u].push_back(v),G[v].push_back(u);
	dfs(1);
	printf("%d\n",(0ll+f[1][0]+f[1][2]+f[1][3])%mod);
	return 0;
}