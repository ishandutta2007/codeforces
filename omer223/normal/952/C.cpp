#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")

#include <bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SIZE 100001
using namespace std;
typedef long long ll;
const ll INF = 1e15;
ll n, t;
string s;

int main() {
    fast;
    cin >> n;
    vector<ll> a(n), b;
    bool ans = true;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) ans &= abs(a[i] - a[i+1]) < 2;
    sort(b.begin(), b.end());
    if (ans) cout << "YES";
    else cout << "NO";
}