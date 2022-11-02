#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

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

    int t;
    cin >> t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	vector<int> res(k + 1);
    	for(int i = 1;i <= k - (n -k) - 1;i++) 
    		res[i] = i;
    	for(int i = k - (n - k);i < k;i++)
    		res[i] = k - (i - (k - (n - k)));
    	res[k] = k - (n - k);
    	for(int i = 1;i <= k;i++)
    		cout << res[i] << " ";
    	cout << endl;
    }
}