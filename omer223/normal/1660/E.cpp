#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <string>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef pair<ld, ld> pld;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    foru(i, 0, n) {
        string s;
        cin >> s;
        foru(j, 0, n)a[i][j]=(s[j]=='1');
    }
    vector<int> diag(n, 0);
    int cnt = 0;
    foru(i, 0, n) {
        foru(j, 0, n) {
            if (a[i][j])diag[(i - j + n) % n]++, cnt++;
        }
    }
    int bst = n * n;
    foru(i, 0, n) {
        int cost = cnt - diag[i] + (n - diag[i]);
        bst = min(bst, cost);
    }
    cout << bst << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}