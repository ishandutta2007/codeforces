#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
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
int n;
void solve(){
	n=read();
	if(n==2){
		puts("1\n2 1\n1\n2 1");
		return;
	}
	if(n==3){
		puts("5\n2 3 1\n2\n1 3\n3 2");
		return;
	}
	ll ans=0;
	FOR(i,n/2+1,n-1) ans+=1ll*(i-1)*(i-1);
	FOR(i,1,n/2) ans+=1ll*(n-i)*(n-i); 
	printf("%lld\n",ans);
	printf("%d ",n/2+1);
	FOR(i,2,n/2-1) printf("%d ",i+1);
	printf("%d ",n);
	FOR(i,n/2+1,n-2) printf("%d ",i+1);
	puts("2 1");
	printf("%d\n",n-1);
	FOR(i,n/2+1,n-1) printf("%d 1\n",i);
	FOR(i,1,n/2) printf("%d %d\n",i,n);
}
int main(){
	int T=read();
	while(T--) solve();
}