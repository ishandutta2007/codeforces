#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010,mod=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
ll n;
int k,f[50];
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int calc(ll p,int c,int k){
	p%=mod;
	f[0]=1;
	FOR(j,1,c) f[j]=1ll*f[j-1]*p%mod;
	FOR(i,1,k) FOR(j,1,c) f[j]=(f[j]+1ll*f[j-1]*j%mod)*qpow(j+1,mod-2)%mod;
	return f[c];
}
int solve(ll n,int k){
	int ans=1;
	for(ll i=2;i*i<=n;i++) if(n%i==0){
		int c=0;
		while(n%i==0) c++,n/=i;
		ans=1ll*ans*calc(i,c,k)%mod;
	}
	if(n>1) ans=1ll*ans*calc(n,1,k)%mod;
	return ans;
}
int main(){
	cin>>n>>k;
	cout<<solve(n,k)<<endl;
}