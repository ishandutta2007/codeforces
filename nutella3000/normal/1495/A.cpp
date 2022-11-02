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

    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vector<int> x(n), y(n);

    	int id1 = 0, id2 = 0;

    	for(int i = 0;i < 2 * n;i++) {
    		int v1, v2;
    		cin >> v1 >> v2;
    		if (v1 == 0) y[id1++] = abs(v2);
    		else x[id2++] = abs(v1);
    	}
    	sort(all(x));
    	sort(all(y));

    	double res = 0;
    	for(int i = 0;i < n;i++) {
    		res += sqrt(x[i] * x[i] + y[i] * y[i]);
    	}

    	cout << res << endl;
    }
}