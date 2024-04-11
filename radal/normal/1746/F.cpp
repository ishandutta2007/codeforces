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
constexpr int N = 3e5+15,mod = 998244353,inf = 1e9+10;
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

map <int,ll> mp;
int a[N],fen[70][N];

void upd(int i,int r,bool f){
	for (; r < N; r |= (r+1)){
		if (f) fen[i][r] += 1;
		else fen[i][r] -= 1;
	}
}

int que(int l,int i){
	int ans = 0;
	for(; l >= 0; l = (l&(l+1))-1)
		ans += fen[i][l];
	return ans;
}
void solve(){
	int n,q;
	cin >> n >> q;
	rep(i,0,n){
	   	cin >> a[i];
		if (mp.find(a[i]) == mp.end()){
			mp[a[i]] = rng()%(1ll*inf*inf);
		}
		ll v = mp[a[i]];
		rep(j,0,64){
			if (v&(1ll << j)){
				upd(j,i,1);
			}
		}
	}
	while (q--){
		int t;
		cin >> t;
		if (t == 1){
			int i,x;
			cin >> i >> x;
			i--;
			if (mp.find(x) == mp.end()){
            	mp[x] = rng()%(1ll*inf*inf);
			}
	        ll v = mp[a[i]];
	        rep(j,0,64){
    	        if (v&(1ll << j)){
        	        upd(j,i,0);
            	}
        	}
			a[i] = x;
			v = mp[x];
            rep(j,0,64){
                if (v&(1ll << j)){
                    upd(j,i,1);
                }
            }
		}
		else{
			int l,r,k;
			cin >> l >> r >> k;
			l--;
			r--;
			bool fl = 1;
			rep(i,0,64){
				int cnt = que(r,i);
				if (l) cnt -= que(l-1,i);
				if (cnt%k){
					fl = 0;
					break;
				}
			}
			cout << ((fl) ? "YES" : "NO") << endl;
		}
	}
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
	int T = 1;
//	cin >> T;
	while (T--){
		solve();
	}
    return 0;
}