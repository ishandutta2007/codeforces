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
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int p[1000010],c[1000010];
int main(){
	int n=gi(),in=pow(n,mod-2),k,ik,x;
	for(int i=1;i<=n;++i){
		k=gi(),ik=pow(k,mod-2);
		while(k--)x=gi(),++c[x],p[x]=(p[x]+ik)%mod;
	}
	int ans=0;
	for(int i=1;i<=1000000;++i)ans=(ans+1ll*p[i]*c[i])%mod;
	printf("%d\n",1ll*in*in%mod*ans%mod);
	return 0;
}