#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d, m;
    cin >> n >> d >> m;
    
    vector<int> smaller, bigger;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        if (u <= m) smaller.push_back(u);
        else bigger.push_back(u);
    }
    sort(smaller.begin(), smaller.end());
    sort(bigger.rbegin(), bigger.rend());
    vector<long long> sumSmall(smaller.size(), 0ll);
    if (!sumSmall.empty()) sumSmall[0] = smaller[0];
    for (int i = 1; i < smaller.size(); i++) {
        sumSmall[i] = sumSmall[i - 1] + smaller[i];
    }

    long long res = 0;
    if (!sumSmall.empty()) res = sumSmall.back();
    long long sumBigger = 0;
    for (int i = 0; i < bigger.size(); i++) {
        sumBigger += bigger[i];
        long long need = 1ll * i * d;
        need -= ((int)bigger.size() - (i + 1));
        need = max(0ll, need);
        if (need > smaller.size()) break;
        long long now = sumBigger;
        if (!sumSmall.empty()) now += sumSmall.back();
        if (need > 0) now -= sumSmall[need - 1];
        res = max(res, now);
    }
    cout << res << endl;
    return 0;
}