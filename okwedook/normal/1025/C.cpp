#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define checkmin(x, y) if (x > y) x = y
#define checkmax(x, y) if (x < y) x = y
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])

template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }

signed main() {
    FAST; FIXED; RANDOM;
    string s;
    cin >> s;
    deque<char> a, b;
    for (auto i : s) b.pb(i);
    b.popf();
	a.pb(s[0]);
    bool mode = false;
    while (b.size() > 0) {
    	if (mode == false) {
    		if (a.back() == b.front()) mode = true;
    	} else {
    		if (a.front() == b.back()) mode = false;
    	}
    	if (mode == false) a.pb(b.front()), b.popf();
    	else a.pf(b.back()), b.popb();
    }
    int ans = 0, curr = 0;
    for (int i = 0; i < a.size(); ++i) {
    	if (i == 0 || a[i] == a[i - 1]) curr = 1;
    	else ++curr;
    	checkmax(ans, curr);
    }
    cout << ans;
    return 0; 
}