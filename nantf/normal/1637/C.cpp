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
int n,a[maxn];
void solve(){
	n=read()-2;read();
	FOR(i,1,n) a[i]=read();
	read();
	if(n==1){
		if(a[1]%2==1) puts("-1");
		else printf("%d\n",a[1]/2);
	}
	else{
		bool flag=false;
		FOR(i,1,n) if(a[i]>1) flag=true;
		if(!flag) puts("-1");
		else{
			ll ans=0;
			FOR(i,1,n) ans+=(a[i]+1)/2;
			printf("%lld\n",ans);
		}
	}
}
int main(){
	int T=read();
	while(T--) solve();
}