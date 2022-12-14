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
 
const int MAX_N = 1e5 + 5;

int a[MAX_N], b[MAX_N], was[MAX_N];
 
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
       
    int n, ans = 0;
	cin >> n;
	forn (i, n)
		cin >> a[i];
	forn (i, n) 
		cin >> b[i];
	reverse(b, b + n);
	int last = 0;
	fornr (i, n) {
		if (a[i] != b[last])
			ans++;
		was[a[i]] = 1;
		while (last < n && was[b[last]])
			last++;
	}
 	cout << ans << "\n";
    return 0;
}