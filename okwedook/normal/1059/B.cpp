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
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (auto &i : arr) cin >> i;
    vector<string> check = arr;
    for (auto &i : check)
        for (auto &j : i) 
            j = '.';
    for (int i = 0; i < n - 2; ++i)
        for (int j = 0; j < m - 2; ++j) {
            bool flag = false;
            for (int k = 0; k < 3; ++k)
                for (int l = 0; l < 3; ++l)
                    if ((k != 1 || l != 1) && arr[i + k][j + l] == '.') {
                        flag = true;
                    }
            if (flag) continue;
            for (int k = 0; k < 3; ++k)
                for (int l = 0; l < 3; ++l)
                    if (k != 1 || l != 1)
                        check[i + k][j + l] = '#';
        }
    if (check == arr) cout << "YES";
    else cout << "NO";
    return 0;
}