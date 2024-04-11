#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n);
    vector<ll> prefix(n + 1);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i-1];

    ll begin = 0, end = 0, ans = 0;

    set<ll> s;
    s.insert(prefix[0]);

    for (begin = 0; begin < n; begin++) {
        while (end < n and !s.count(prefix[end + 1])) {
            end += 1;
            s.insert(prefix[end]);
        }
        ans += end - begin;
        s.erase(prefix[begin]);
    }

    cout << ans;
    return 0;
}