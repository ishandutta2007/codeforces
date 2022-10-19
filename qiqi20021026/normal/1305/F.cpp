#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define inf 1010000000
#define infll 1010000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define cbn(x,y) ((ll)fac[x]*inv[y]%mod*inv[(x)-(y)]%mod)
#define N 1000009
using namespace std;

int read(); ll readll();

int n,cnt,tp,q[N],prm[N]; bool vis[N]; pll b[N]; map<ll,int> mp; ll a[N];
void add(ll i){
	if (!mp[i]){ mp[i]=++tp; b[tp].se=i; }
	b[mp[i]].fi--;	
}
void work(ll x){
	if (x<=1) return;
	for (int i=1; i<=cnt && (ll)i*i<=x; i++) if (!(x%prm[i])){
		add(prm[i]); for (; !(x%prm[i]); x/=prm[i]);		
	}
	if (x>1) add(x);
}
ll solve(ll p){
	ll tmp=0;
	for (int i=1; i<=n; i++) tmp+=min(a[i]>=p?a[i]%p:inf,p-a[i]%p);
	return tmp;
}
int main(){
	for (int i=2; i<N; i++) if (!vis[i]){
		prm[++cnt]=i;
		for (int j=i<<1; j<N; j+=i) vis[j]=1;
	}
	n=read();
	for (int i=1; i<=n; i++) a[i]=readll();
	for (int i=1; i<=n; i++) q[i]=i;
	random_shuffle(q+1,q+n+1);
	for (int i=1; i<=n && i<=100; i++){
		work(a[q[i]]);
		work(a[q[i]]-1);
		work(a[q[i]]+1);
	}
	sort(b+1,b+tp+1);
	ll ans=infll;
	for (int i=1; i<=tp && i<=30; i++) ans=min(ans,solve(b[i].se));
	printf("%lld\n",ans);
	return 0;
}

int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}