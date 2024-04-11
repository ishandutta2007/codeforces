#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
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
int n,m,k,a[maxn],b[maxn];
void clear(){
	FOR(i,1,k) a[i]=b[i]=0;
	n=m=k=0;
}
void solve(){
	n=read();m=read();k=read();
	FOR(i,1,k) a[i]=read();
	ll sn=0,sm=0;
	// 0,2~tmp
	FOR(i,1,k) b[i]=a[i]/m;
	sort(b+1,b+k+1,greater<int>());
	ll s=0;
	FOR(i,1,k){
		if(b[i]<2) break;
		s+=b[i]-2;
		if(2*i<=n && 2*i+s>=n) return puts("Yes"),clear();
	}
	FOR(i,1,k) b[i]=a[i]/n;
	sort(b+1,b+k+1,greater<int>());
	s=0;
	FOR(i,1,k){
		if(b[i]<2) break;
		s+=b[i]-2;
		if(2*i<=m && 2*i+s>=m) return puts("Yes"),clear();
	}
	puts("No");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}