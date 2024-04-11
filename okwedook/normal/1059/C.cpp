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
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<ll> arr(n);
    vector<bool> used(n + 1);
    for (int i = 0; i < n; ++i)
        arr[i] = i + 1;
    for (auto i : arr)
        used[i] = true;
    ll curr = 1;
    while (sz(arr) > 0) {
        int cnt = -1, num = 0;
        for (int j = (arr[0] == 1); j < sz(arr); ++j) {
            int i = arr[j];
            int left = 0;
            for (int j = i; j <= n; j += i)
                left += used[j];
            if (left < sz(arr) && (left > cnt || left == cnt && num < i)) {
                cnt = left;
                num = i;
            }
        }
        if (cnt == -1) {
            for (int i = 1; i < sz(arr); ++i)
                cout << curr << ' ';
            cout << arr.back();
            return 0;
        }
        vector<ll> brr;
        for (auto i : arr)
            if (i % num != 0) cout << curr << ' ', used[i] = false;
            else brr.pb(i);
        curr = num;
        arr = brr;
    }
    return 0;
}