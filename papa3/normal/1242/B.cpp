#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define cerr if (true) {} else cout
#define pisz(x) cout << #x << ": " << x << endl;

set<int> active;
int ojciec[1000010];
int roz[1000010];
vector<int> drogi[1000010];

int f(int gdzie) {
    if (gdzie == ojciec[gdzie]) {
        return gdzie;
    }
    return ojciec[gdzie] = f(ojciec[gdzie]);
}

void u(int a, int b) {
    a = f(a);
    b = f(b);
    if (a == b) return;
    ojciec[a] = b;
    roz[b] += roz[a];
    active.erase(a);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        ojciec[i] = i;
        roz[i] = 1;
    }
    for (int a, b, i = 1; i <= m; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        drogi[b].push_back(a);
    }

    map<int, int> s;
    for (int i = 1; i <= n; i++) {
        s.clear();
        active.insert(i);
        for (int j : drogi[i]) {
            s[f(j)]++;
        }

        vector<int> v;
        for (int j : active) {
            if (s[j] < roz[j]) {
                v.push_back(j);
            }
        }
        for (int j : v) {
            u(i, j);
        }
    }

    cout << (int)active.size() - 1;


    return 0;
}
/*

*/