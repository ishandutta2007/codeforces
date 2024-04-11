#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
  
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
 
#define FNAME ""
 
const int N = 2e5 + 5;

pii a[N];
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i].fst;
    forn (i, n)
        cin >> a[i].snd;
    sort(a, a + n);
    int it = 0, cur = 0;
    ll sum = 0, ans = 0;
    multiset<int> s;
    while (it < n || sz(s)) {
        if (sz(s) == 0)
            cur = a[it].fst;
        while (it < n && a[it].fst == cur)
            s.insert(a[it].snd), sum += a[it].snd, it++;
        sum -= *(--s.end());
        s.erase(--s.end());
        ans += sum;
        cur++;
    }
    cout << ans << "\n";
	return 0;
}