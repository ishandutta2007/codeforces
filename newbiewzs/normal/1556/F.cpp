#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=15;
const int mod=1e9+7;
int n,a[N],t[1<<14];
int ksm(int x,int k){
	x%=mod;
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mod;
		k>>=1;
		x=1ll*x*x%mod;
	}
	return base;
}
int h[N][1<<14],f[1<<14];
int js(int x,int S){
	int tmp=1;
	for(int j=1;j<=n;j++){
		if(x&(1<<j-1))tmp=1ll*tmp*h[j][S]%mod;
	}
	return tmp;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),t[1<<(i-1)]=a[i];
	for(int i=1;i<=n;i++){
		h[i][0]=1;
		for(int k=1;k<(1<<n);k++){
			int low=(k&(-k));
			h[i][k]=1ll*h[i][k^low]*a[i]%mod*ksm(a[i]+t[low],mod-2)%mod;
		}
	}
	int zs=(1<<n)-1;
	int ans=0;
	for(int i=1;i<(1<<n);i++){
		int tmp=1;
		for(int k=(i-1)&i;k;k=(k-1)&i){
			tmp=(tmp-1ll*f[k]*ksm(js(k,zs^i),mod-2)%mod+mod)%mod;
		}
		f[i]=1ll*js(i,zs^i)*tmp%mod;
		ans=(ans+1ll*f[i]*__builtin_popcount(i)%mod)%mod;
	}
	cout<<ans;
	return 0;
}