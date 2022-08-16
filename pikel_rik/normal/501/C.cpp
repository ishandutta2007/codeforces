#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = (1 << 16);

int n;
int degree[N], s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> one;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> degree[i] >> s[i];
        if (degree[i] == 1) one.insert(i);
    }

    vector<pi> ans;

    while (!one.empty()) {
        int x = *(one.begin());
        one.erase(x);

        degree[s[x]] -= 1;
        s[s[x]] ^= x;

        if (degree[s[x]] == 0)
            one.erase(s[x]);
        else if (degree[s[x]] == 1) {
            one.insert(s[x]);
        }
        ans.emplace_back(x, s[x]);
    }

    cout << ans.size() << "\n";
    for (const pi &x : ans) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}