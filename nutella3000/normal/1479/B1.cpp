#include <bits/stdc++.h>
 
using namespace std;
 
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
  
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
 
const int inf = 1e9 + 7;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++)
    	cin >> a[i];
    vector<pii> b;
    int cnt = 0, lst = a[0];
    for(int i = 0;i <= n;i++) {
    	if (i != n && a[i] == lst) cnt++;
    	else {
    		b.emplace_back(a[i - 1], cnt);
    		cnt = 1;
    		lst = a[i];
    	}
    }


    int ind = 0, res = 0;
    lst = -1;

    for(int i = 0;i < sz(b);i++) {
    	if (b[i].se == 1) {
    		res++;
    	}
    	else {
    		int c2 = 0;
    		for(int j = ind;j < i;j++) {
    			if (b[j].fi == b[i].fi) c2++;
    		}
    		int c = i - ind;
    		if (b[i].fi == lst && (c2 * 2 + 1 == c)) res++;
    		else res += 2;

    		lst = b[i].fi;
    		ind = i + 1;
    	}
    }
    cout << res;
}