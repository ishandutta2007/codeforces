#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e6+10, ALP = 26, MAXL = 20, INF = 1e9+10, MOD = 1e9+7;

vector<ll> a;
int n, k;
bool v(int x, int cur) {
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(!cur)  ans++, cur ^= 1;
		else if(a[i] <= x)  ans++, cur ^= 1;
	}
	return ans >= k;
}
void solve(){
    cin >> n >> k; a.clear();
    for (int i = 0; i < n; i++){
        ll c; cin >> c; a.push_back(c);
    }
    ll lo = -1, hi = 1e9+10, mid = (lo+hi)/2;
    while (lo < mid && mid < hi){
        if (v(mid, 1) || v(mid, 0)) hi = mid;
        else lo = mid;
        mid = (lo+hi)/2;
    }
    // if (hi <= 0) cout << (*min_element(a.begin(), a.end())) << "\n";
    cout << hi << "\n";
}
int main(){
    int t=1; //cin >> t;
    while (t--) solve();
}