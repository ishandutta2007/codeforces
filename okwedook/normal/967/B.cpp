#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf pop_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-8
#define mod 1000000009
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2>inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1>inline void sort(vector<T1> &arr) { sort(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
    ll n, A, B;
    cin >> n >> A >> B;
    vector<ll> s(n);
    for (auto &i : s) cin >> i; 
    ll first = s[0];
    sort(s.begin() + 1, s.end());   
    ll summ = 0;
    for (auto i : s) summ += i;
    if (first * A >= B * summ) {
        cout << 0;
        return 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        summ -= s[i];
        if (first * A >= B * summ) {
            cout << n - i;
            return 0;
        }
    }
    return 0;
}