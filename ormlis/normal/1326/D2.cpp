#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e6 + 1;
const int m = 1e9 + 7;
const int P = 998244353;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };
int sP[maxN];

int madd(int a, int b) {
    if (a + b >= m) {
        return a + b - m;
    }
    return a + b;
}

int msub(int a, int b) {
    if (a - b < 0) {
        return a - b + m;
    }
    return a - b;
}

int mul(int a, int b) {
    return 1ll * a * b % m;
}


vector<int> HashesB (string &s) {
    vector<int> hashes(s.size());
    sP[0] = 1;
    hashes[0] = s[0];
    for(int i=1; i < (int)s.size(); ++i) {
        sP[i] = mul(sP[i - 1], P);
        hashes[i] = madd(mul(hashes[i - 1], P), s[i]);
    }
    return hashes;
}

// [l; r]
int Gethash(int l, int r, vector<int> &hashes) {
    if (l == 0) {
        return hashes[r];
    }
    return msub(hashes[r], mul(hashes[l - 1], sP[r - l + 1]));
}

void solve() {
    string s; cin >> s;
    auto h1 = HashesB(s);
    reverse(all(s));
    auto h2 = HashesB(s);
    reverse(all(s));
    int n = s.size();
    ar<int, 3> ans = {1, 0, n-1};
    for(int i = 0, j = n - 1; i < n; ++i) {
        while(j >= i && n - j - 1 <= i && s[n-j-1] == s[j]) j--;
        if (i > j) j++;
        if (Gethash(n-j-1, i, h1) == Gethash(n-1-i, j, h2)) ans = max(ans, {i + n - j, i, j});
    }
    for(int j = n - 1, i = 0; j >= 0; --j) {
        while(i <= j && n-i-1 >= j && s[i] == s[n-i-1]) i++;
        if (i > j) i--;
        if (Gethash(j, n-i-1, h1) == Gethash(i, n-1-j, h2)) ans = max(ans, {i + n - j, i-1, j-1});
    }
    string t = s.substr(0, ans[1] + 1) + s.substr(ans[2] + 1, n);
    cout << t << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}