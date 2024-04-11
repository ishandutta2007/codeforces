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
int n,b[maxn];
PII a[maxn];
bool vis[maxn];
void clear(){
	FOR(i,1,n) vis[i]=false;
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=MP(read(),i);
	FOR(i,1,n) b[i]=read();
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	bool flag=true;
	ROF(i,n,1){
		if(a[i].first==b[i]) continue;
		if(vis[a[i].second]) flag=false;
		vis[a[i].second]=true;
		a[i].first++;
		sort(a+1,a+n+1);
		if(a[i].first!=b[i]) flag=false;
	}
	puts(flag?"YES":"NO");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}