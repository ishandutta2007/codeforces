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
constexpr int N = 5e2+15,mod = 1e9+7,inf = 1e9+10;
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

int a[N],b[N],lst[N];
vector<pll> ans;
map<pll,int> mp;
void rev(int l,int r){
	ans.pb({l,r});
	while (r > l){
		swap(a[l],a[r]);
		l++;
		r--;
	}
}

void solve(){
	ans.clear();
	int n;
	cin >> n;
	rep(i,1,n+1) cin >> a[i];
	rep(i,1,n+1) cin >> b[i];
	if (a[1] != b[1] || a[n] != b[n]){
		cout << "NO" << endl;
		return;
	}
	mp.clear();
	rep(i,1,n){
		int x = min(a[i],a[i+1]),y = max(a[i],a[i+1]);
		mp[{x,y}]++;
	   	x = min(b[i],b[i+1]),y = max(b[i],b[i+1]);
        mp[{x,y}]--;
	}
	for (auto p : mp){
		if (p.Y){
			cout  << "NO" << endl;
			return;
		}
	}
	rep(i,2,n){
		if (a[i] == b[i]) continue;
		rep(j,i+1,n){
			if (a[j] == b[i] && a[j+1] == a[i-1]){
				rev(i-1,j+1);
				break;
			}
		}
		if (a[i] == b[i]) continue;
		int ind = -1;
		rep(j,1,n+1) lst[a[j]] = j;
		rep(j,i+1,n+1) if (a[j] == b[i] && a[j-1] == a[i-1]){
			ind = j;
			break;
		}
		if (ind != lst[a[i-1]]+1){
			rev(ind-1,lst[a[i-1]]);
			rev(i-1,lst[a[i-1]]);
			continue;
		}
		rep(j,i,ind){
			if (lst[a[j]] >= ind){
				rev(j,lst[a[j]]);
				rep(k,i+1,n){
					if (a[k] == b[i] && a[k+1] == a[i-1]){
						rev(i-1,k+1);
						break;
					}
				}
				break;
			}
		}
		if (a[i] != b[i]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl << ans.size() << endl;
	for (auto p : ans) cout << p.X << ' ' << p.Y << endl;
}

int main(){
	ios :: sync_with_stdio(0); cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--){
		solve();
	}
}