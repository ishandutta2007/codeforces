#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int k;
    cin >> k;

    string s;
    cin >> s;

    int n = s.length();

    vi pos;
    pos.push_back(-1);

    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            pos.push_back(i);
    }

    pos.push_back(n);

    if (k == 0) {
        ll ans = 0;
        for (int i = 1; i < pos.size(); i++) {
            ll len = pos[i] - pos[i-1] - 1;
            ans += len * (len + 1) / 2;
        }
        cout << ans << "\n";
    }
    else {
        ll ans = 0;
        for (int i = 1; i + k < pos.size(); i++) {
            ans += (pos[i] - pos[i-1]) * (ll)(pos[i + k] - pos[i + k - 1]);
        }
        cout << ans <<"\n";
    }
    return 0;
}