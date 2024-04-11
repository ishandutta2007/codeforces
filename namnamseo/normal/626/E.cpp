#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n;
ll a[200'010];
ll s[200'010];

struct frac {
	ll mo, ja;
	frac(ll M=1, ll J=0){
		mo=M; ja=J;
		if(mo<0) mo=-mo, ja=-ja;
	}
	bool operator<(const frac&r) const{
		return ja*r.mo < mo*r.ja;
	}
};

frac avg(int k, int i){ return frac(2*k+1, s[i]-s[i-1-k]+s[n]-s[n-k]);}
frac avg2(int k, int i){ return frac(2*k+2, s[i+1]-s[i-1-k]+s[n]-s[n-k]);}

bool test(int k, int i){
	return avg(k-1, i) < avg(k, i);
}
bool test2(int k, int i){
	return avg2(k-1, i) < avg2(k, i);
}

frac ansv(1, -1);
int ansi, ansk;
bool ans2;

int main()
{
	read(n);
	for(int i=1; i<=n; ++i) read(a[i]);
	sort(a+1, a+n+1);
	for(int i=1; i<=n; ++i) s[i]=s[i-1]+a[i];

	for(int i=1; i<=n; ++i){
		{
		int maxlen = min(i-1, n-i);
		int L = 0, R = maxlen+1;
		while(L+1 < R){
			int mid=(L+R)/2;
			(test(mid, i)?L:R) = mid;
		}
		ll js = s[i]-s[i-L-1]+s[n]-s[n-L];
		js -= (2*L+1LL)*a[i];
		frac curv(2*L+1, js);
		if(ansv < curv){
			ansv = curv;
			ansi = i; ansk = L; ans2 = 0;
		}
		}
		if(i+1<=n){
		int maxlen = min(i-1, n-i-1);
		int L = 0, R = maxlen+1;
		while(L+1 < R){
			int mid=(L+R)/2;
			(test2(mid, i)?L:R) = mid;
		}
		ll js = s[i]-s[i-L-1]+s[n]-s[n-L];
		js -= (L+1LL)*(a[i]+a[i+1]);
		frac curv(2*L+2, js);
		if(ansv < curv){
			ansv = curv;
			ansi = i; ansk = L; ans2 = 1;
		}
		}
	}
	vector<int> ans;
	ans.pb(a[ansi]);
	for(int i=1; i<=ansk; ++i){
		ans.pb(a[ansi-i]);
		ans.pb(a[n+1-i]);
	}
	if(ans2) ans.pb(a[ansi+1]);
	printf("%d\n", int(ans.size()));
	for(int x:ans) printf("%d ", x);
	return 0;
}