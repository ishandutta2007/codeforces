#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int CC[5110][5110];
il int C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	return CC[n][m];
}
il int solve(int n,int m,int lim){
	if(n==0)return 1;
	if(n<0)return 0;
	int ans=0;
	for(int i=0;i<=m;++i)ans=(ans+1ll*((i&1)?998244352:1)*C(m,i)%mod*C(n-lim*i+m-1,m-1))%mod;
	return ans;
}
int inv[101];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	CC[0][0]=1;
	for(int i=1;i<=5109;++i){
		CC[i][0]=1;
		for(int j=1;j<=i;++j)CC[i][j]=(CC[i-1][j]+CC[i-1][j-1])%mod;
	}
	int p=gi(),s=gi(),r=gi();
	int ans=0;
	inv[1]=1;for(int i=2;i<=p;++i)inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
	for(int x=r;x<=s;++x)
		for(int i=1;i<=p;++i){
			if((p-i)*(x-1)+i*x<s)continue;
			ans=(ans+1ll*C(p-1,i-1)*solve(s-i*x,p-i,x)%mod*inv[i])%mod;
		}
	printf("%d\n",1ll*ans*pow(C(s-r+p-1,p-1),mod-2)%mod);
	return 0;
}