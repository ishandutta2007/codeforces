#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
         
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define all(b) b.begin(), b.end()
#define fi first
#define se second
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n;
    cin >> n;
    vector<int> p(n), pref(n), suf(n), dp1(n), dp2(n);

    for(int i = 0;i < n;i++)
    	cin >> p[i];
    	
  	int mx1 = -inf, id1 = -1, mx2 = -inf, id2 = -2;

    for(int i = 1;i < n;i++) {
    	if (p[i] > p[i - 1]) dp1[i] = 1 + dp1[i - 1];

    	if (mx1 == dp1[i]) id1 = -1;
    	else if (mx1 < dp1[i]) {
    		mx1 = dp1[i];
    		id1 = i;
    	}
    }

    for(int i = n - 2;i >= 0;i--) {
    	if (p[i] > p[i + 1]) dp2[i] = 1 + dp2[i + 1];

    	if (mx2 == dp2[i]) id2 = -2;
    	else if (mx2 < dp2[i]) {
    		mx2 = dp2[i];
    		id2 = i;
    	}
    }

    cout << (id1 == id2 && mx1 == mx2 && mx1 % 2 == 0);
}