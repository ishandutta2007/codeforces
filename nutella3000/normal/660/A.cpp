#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e17 + 7;

int gcd(int a, int b) {
    if (b == 0) 
        return a;
    return gcd(b, a % b);
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> res;
    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        if (res.size() && gcd(v, res[res.size() - 1]) != 1) 
            res.emplace_back(998244353);

        res.emplace_back(v);
    }

    cout << res.size() - n << endl;
    for(int i : res)
        cout << i << " ";

    cout << endl;
}