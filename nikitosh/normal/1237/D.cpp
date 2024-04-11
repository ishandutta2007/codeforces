#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
 
#define FNAME ""
 
const int MAX_N = 3e5 + 5, INF = 1e9 + 10;

int a[MAX_N], t[4 * MAX_N], ans[MAX_N], res[MAX_N]; 
set<int> s; 
 
int go(int v, int tSize, int k) {
	if (v >= tSize)
		return v - tSize;
	if (t[2 * v] <= k)
		return go(2 * v, tSize, k);
	return go(2 * v + 1, tSize, k);
} 
 
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
       
	int n;
	cin >> n;
	forn (i, n)
		cin >> a[i];
	int minn = *min_element(a, a + n);
	int maxx = *max_element(a, a + n);
 	if (2 * minn >= maxx) {
 		forn (i, n)
 			cout << "-1 ";
 		return 0;
 	}
 	forn (i, n)
 		a[n + i] = a[2 * n + i] = a[i];
	int tSize = 1;
	while (tSize < 3 * n)
		tSize *= 2;
	forn (i, 2 * tSize)
		t[i] = INF;
 	fornr (i, 3 * n) {
 		int k = a[i] / 2;
 		if (a[i] % 2 == 0)
 			k--;
 		int v = tSize + i;
 		int ind = v;
 		while (ind > 0)
 			t[ind] = min(t[ind], a[i]), ind /= 2;
 		while (v > 0 && t[v] > k)
 			v /= 2;
 		if (v == 0) {
 			ans[i] = INF;
 			continue;
 		}
 		ans[i] = go(v, tSize, k);
 	}
 	for (int i = 2 * n - 1; i >= n; i--)
 		s.insert(ans[i]);
 	fornr (i, n) {
 		s.insert(ans[i]);
 		res[i] = *s.begin() - i;
 	}
 	forn (i, n)
 		cout << res[i] << " ";
    return 0;
}