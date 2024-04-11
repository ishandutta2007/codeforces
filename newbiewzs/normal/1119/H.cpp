#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#include<vector>
#include<ctime>
#include<cmath>
#include<bitset>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=(1<<17)+5;
const int mod=998244353;
int n,m,x,y,z,summ,a,b,c;
int ans[N];
int a1[N],a2[N],a3[N];
int t[2][2],ct[2][2];
void xo(int f[],int s[2][2]){
	for(int i=1;i<(1<<m);i*=2){
		for(int k=0;k<(1<<m);k+=i*2){
			for(int j=0;j<i;j++){
				int tmp=f[k+j];
				f[k+j]=((1ll*f[k+j]*s[0][0]%mod+1ll*f[k+j+i]*s[0][1]%mod)%mod+mod)%mod;
				f[k+j+i]=((1ll*tmp*s[1][0]%mod+1ll*f[k+j+i]*s[1][1]%mod)%mod+mod)%mod;
			}
		}
	}
}
int ksm(int x,int k){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
signed main(){
	n=read();m=read();
	x=read();y=read();z=read();
	int inv2=ksm(2,mod-2),inv4=ksm(4,mod-2);
	for(int i=1;i<=n;i++){
		a=read();b=read();c=read();
		summ^=a;b^=a;c^=a;
		a1[b]++;a2[c]++;a3[b^c]++;
	}
	t[0][0]=t[0][1]=t[1][0]=1;t[1][1]=mod-1;
	ct[0][0]=ct[0][1]=ct[1][0]=inv2;ct[1][1]=mod-inv2;
	xo(a1,t);xo(a2,t);xo(a3,t);
	ll t1=1ll*(x+y+z)%mod,t2=1ll*(x+y-z+mod)%mod,t3=1ll*(x-y+z+mod)%mod,t4=1ll*(x-y-z+mod+mod)%mod;
	for(int i=0;i<(1<<m);i++){
		ll d1=1ll*((n+a1[i]+a2[i]+a3[i])%mod+mod)%mod*inv4%mod;
		ll d2=1ll*((n+a1[i]-a2[i]-a3[i])%mod+mod)%mod*inv4%mod;
		ll d3=1ll*((n-a1[i]+a2[i]-a3[i])%mod+mod)%mod*inv4%mod;
		ll d4=1ll*((n-a1[i]-a2[i]+a3[i])%mod+mod)%mod*inv4%mod;
		ans[i]=1ll*ksm(t1,d1)*ksm(t2,d2)%mod*ksm(t3,d3)%mod*ksm(t4,d4)%mod;
	}
	xo(ans,ct);
	for(int i=0;i<(1<<m);i++){
		cout<<ans[i^summ]<<" ";
	}
	return 0;
}