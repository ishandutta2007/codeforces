#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        for (auto &j : arr[i]) {
            if (j == '0') {
                cout << "No";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (arr[i][j] != '*') {
                if (arr[i][j] == '.') arr[i][j] = '0';
                int cnt = 0;
                for (int k = -1; k < 2; ++k)
                    for (int l = -1; l < 2; ++l) 
                        if (i + k >= 0 && i + k < n && j > l >= 0 && j + l < m)
                            cnt += (arr[i + k][j + l] == '*');
                if (arr[i][j] - '0' != cnt) {
                    cout << "No";
                    return 0;
                }
            }   
    cout << "Yes";
    return 0; 
}