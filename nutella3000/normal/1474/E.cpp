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
       
const int inf = 2e9 + 7;



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
    	int r = 0;
    	int id = (n + 1) / 2;

    	vector<int> res(n);
    	res[0] = id;
    	for(int i = id;i < n - 1;i++)
    		res[i] = i + 1, r += i * i;

    	res[n - 1] = id - 1;
    	for(int i = id - 1;i > 0;i--)
    		res[i] = i - 1, r += (n - 1 - i) * (n - 1 - i);

    	cout << r + (n - 1) * (n - 1) << endl;

    	for(int i : res)
    		cout << i + 1 << " ";
    	cout << endl;

    	cout << n - 1 << endl;
    	for(int i = id;i < n - 1;i++)
    		cout << i + 1 << " " << 1 << endl;
    	for(int i = id - 1;i >= 1;i--)
    		cout << i + 1 << " " << n << endl;
    	cout << 1 << " " << n << endl;
    }
}