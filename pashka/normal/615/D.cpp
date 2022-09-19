#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>

// @author: pashka

#define MOD 1000000007


using namespace std;

long long int pow(long long int i, long long int p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        auto res = pow(i, p / 2);
        return (res * res) % MOD;
    } else {
        auto res = pow(i, p - 1);
        return (res * i) % MOD;
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    int n; cin >> n;
    map<long long, long long> pm;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pm[x]++;
    }

    vector<pair<long long, long long>> p;

    for (auto pp: pm) {
        p.push_back(pp);
    }

    int m = p.size();

    vector<long long> sl(m);
    vector<long long> sr(m);

    sl[0] = 1;
    for (int i = 1; i < m; i++) {
        sl[i] = sl[i - 1] * (p[i - 1].second + 1) % (MOD - 1);
    }

    sr[m - 1] = 1;
    for (int i = m - 2; i >= 0; i--) {
        sr[i] = sr[i + 1] * (p[i + 1].second + 1) % (MOD - 1);
    }

    long long res = 1;

    for (int i = 0; i < m; i++) {
        auto p2 = sl[i] * sr[i] % (MOD - 1);

        long long t = (p[i].second * (p[i].second + 1)) / 2 % (MOD - 1);

        p2 = p2 * t  % (MOD - 1);

        res *= pow(p[i].first, p2);
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}