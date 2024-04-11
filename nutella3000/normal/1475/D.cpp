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
const int max_n = 2e5 + 3;

vector<int> g1[max_n], g2[max_n];


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	int n, m;
    	cin >> n >> m;
    	vector<int> a(n), b(n);
    	vector<vector<int>> c(2);
    	for(int i = 0;i < n;i++)
    		cin >> a[i];
    	for(int i = 0;i < n;i++)
    		cin >> b[i];
    	int res = 0;
    	for(int i = 0;i < n;i++)
    		c[b[i] - 1].emplace_back(a[i]);

    	sort(all(c[0]), [](int v1, int v2) {return v1 > v2;});
    	sort(all(c[1]), [](int v1, int v2) {return v1 > v2;});

    	int id1 = 0, id2 = 0;
    	int num = 0;
    	while(res < m) {
    		if (id1 == sz(c[0]) && id2 == sz(c[1])) break;
    		bool big = false;
    		{
    			if (id1 == sz(c[0])) big = false;
    			else if (id2 == sz(c[1])) big = true;
    			else {
    				if (c[0][id1] * 2 > c[1][id2]) big = true;
    				if (c[0][id1] + res >= m) big = true;
    			}
    		}
    		//cout << big << endl;
    		if (big) {
    			res += c[0][id1++];
    			num++;
    		}else {
    			res += c[1][id2++];
    			num += 2;
    		}
    	}
    	if (id1 > 0 && res - c[0][id1 - 1] >= m) num--;

    	if (res < m) cout << -1 << endl;
    	else cout << num << endl;
   }
}