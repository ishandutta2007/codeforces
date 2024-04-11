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

    int res = 0;
    set<int> b1{-1};
    int b2 = -1;
    for(pii i : b) {
    	if (i.fi == b2) continue;
    	if (b1.count(i.fi)) {
    		b1.clear();
    		b1.emplace(i.fi);
    		continue;
    	}
    	b1.emplace(b2);
    	b2 = i.fi;
    	res++;
    }   
    cout << res;
}