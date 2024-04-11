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

    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    int sz = 2;
    while((1 << (sz - 1)) <= len) sz++;

    vector<vector<pii>> a(sz);
    int m = 0;
    for(int i = 1;i < sz;i++) {
    	for(int j = 0;j < i;j++)
    		a[i].emplace_back(j, (j == 0 ? 1 : (1 << (j - 1))));
    	m += i;
    }

    vector<pii> b;

    if (l == 1) {
    	b.emplace_back(0, 1);
    	len--;
    	l++;
    }
    for(int i = sz - 1;i > 0;i--) {
    	if (len >= (1 << (i - 1))) {
    		//cout << i << " " << len << endl;
    		b.emplace_back(i, l - 1);
    		l += (1 << (i - 1));
    		len -= (1 << (i - 1));
    	}
    }

    /*for(pii i : b)
    	cout << i.fi << " " << i.se << endl;*/
    map<int, int> conv;
    for(int i = 0;i < sz;i++) {
    	conv[i] = sz + 1 - i;
    }
    conv[sz] = 1;
    cout << "YES" << endl << sz + 1 << " " << m + sz(b) << endl;

    for(int i = 0;i < sz;i++) {
    	for(pii j : a[i])
    		cout << conv[i] << " " << conv[j.fi] << " " << j.se << endl;
    }
    for(pii i : b)
    	cout << 1 << " " << conv[i.fi] << " " << i.se << endl;
}