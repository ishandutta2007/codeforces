#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,a[maxn],fac[maxn],invfac[maxn],cnt[maxn],tot,ans;
inline int C(int n,int m){
	if(n<0 || n<m || m<0) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
inline int f(int n,int m){
	return C(n+m-1,m-1);
}
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	fac[0]=1;
	FOR(i,1,n+a[n]) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n+a[n]]=qpow(fac[n+a[n]],mod-2);
	ROF(i,n+a[n]-1,0) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	int cur=1;
	FOR(i,0,a[n]){
		while(cur<=n && a[cur]<i) cnt[a[cur++]%n]++;
		if(i) tot+=cnt[(i-1)%n];
		if(tot>i) break;
		ans=(ans+f(i-tot,n))%mod;
		ans=(ans-f(i-tot-(n-cur+1),n)+mod)%mod;
	}
	printf("%d\n",ans);
}