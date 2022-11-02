#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
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

const int inf = 1e9 + 4;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

   	int t;
   	cin >> t;
   	while(t--) {
   		string s;
   		cin >> s;
   		int n = sz(s);
   		int res = 0;
   		for(int i = 1;i < n;i++) {
   			if (s[i] == s[i - 1] || (i > 1 && s[i] == s[i - 2])) {
   				s[i] = 45 + (i % 10);
   				res++;
   			}
   		}
   		cout << res << endl;
   	}
}