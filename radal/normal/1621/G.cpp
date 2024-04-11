#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e5+15,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}

int r[N],a[N],en[N],fen[N],st[N];
vector<int> ve;
vector<pll> su;

void upd(int r,int x){
	for (; r < N; r |= (r+1)){
		fen[r] = mkay(fen[r],x);
	}
}

int que(int l,int r){
	int ans = 0;
	l--;
	r--;
	for (; r >= 0; r = (r&(r+1))-1)
		ans = mkay(ans,fen[r]);
	for (; l >= 0; l = (l&(l+1))-1){
		ans -= fen[l];
		if (ans < 0) ans += mod;
	}
	return ans;
}
void solve(){
	memset(fen,0,sizeof fen);
	ve.clear();
	su.clear();
	int n;
	cin >> n;
	rep(i,0,n){
		en[i] = 0;
		st[i] = 0;
		r[i] = -1;
 		cin >> a[i];
		ve.pb(a[i]);
	}
	sort(all(ve));
	ve.resize(unique(all(ve))-ve.begin());
	rep(i,0,n){
		a[i] = lower_bound(all(ve),a[i])-ve.begin()+1;
	}

	upd(0,1);
	rep(i,0,n){
		en[i] = que(0,a[i]);
		upd(a[i],en[i]);
	}

	memset(fen,0,sizeof fen);

	upd(n+1,1);
	repr(i,n-1,0){
		st[i] = que(a[i]+1,n+2);
		upd(a[i],st[i]);
	}

	memset(fen,0,sizeof fen);

	int mx = -1;
	repr(i,n-1,0){
		if (a[i] <= mx){
			if (mx == a[i]) r[i] = -1;
			else{
				auto j = lower_bound(all(su),make_pair(a[i],n+1))-su.begin();
				r[i] = su[j].Y;
			}
		   	continue;
		}
		r[i] = -1;
		mx = a[i];
		su.pb({mx,i});
	}
	int ans = 0;
	repr(i,n-1,0){
		if (r[i] == -1){
			upd(a[i],1);
			continue;
		}
		int calc = mkay(1,que(a[i]+1,a[r[i]]));
		upd(a[i],calc);
		st[i] -= calc;
		if (st[i] < 0) st[i] += mod;
		ans = mkay(ans,1ll*en[i]*st[i]%mod);
	}
	cout << ans << endl;
}
int main(){
	ios :: sync_with_stdio(0); cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--){
		solve();
	}
}