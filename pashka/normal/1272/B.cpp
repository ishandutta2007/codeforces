#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    string s;
    cin >> s;
    int nl = 0, nr = 0, nd = 0, nu = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') nl++;
        if (s[i] == 'R') nr++;
        if (s[i] == 'U') nu++;
        if (s[i] == 'D') nd++;
    }
    nl = nr = min(nl, nr);
    nd = nu = min(nu, nd);
    if (nu == 0) {
        nr = nl = min(nr, 1);
    }
    if (nl == 0) {
        nu = nd = min(nu, 1);
    }
    string res = "";
    for (int i = 0; i < nu; i++) res += "U";
    for (int i = 0; i < nr; i++) res += "R";
    for (int i = 0; i < nd; i++) res += "D";
    for (int i = 0; i < nl; i++) res += "L";
    cout << res.size() << "\n" << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}