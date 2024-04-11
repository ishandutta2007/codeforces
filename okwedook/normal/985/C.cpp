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
bool used[100000];

signed main() {
    FAST; FIXED; RANDOM;
    ll n, k, l;
    cin >> n >> k >> l;
    ll m = n * k;
    vector<ll> arr(m);
    for (auto &i : arr) cin >> i;
    sort(arr);
    if (arr[n - 1] - arr[0] > l) {
    	cout << 0;
    	return 0;
    }
    ll unused = 0;
    ll curr = m - 1;
    ll ans = 0;
    for (int i = m - 1; i >= 0; --i) {
    	if (arr[i] - arr[0] <= l && unused >= k - 1) {
    		ans += arr[i];
    		used[i] = true;
    		ll cnt = k - 1;
    		while (cnt > 0) {
    			if (!used[curr]) --cnt, used[curr] = true, --unused; 
    			--curr;
    		}
    	} else ++unused;
    }
    cout << ans;
    return 0; 
}