#include <bits/stdc++.h>

using namespace std;

int n;

long long go(int u) {
    int num = n / u;
    return (long long)num * (num - 1) * u / 2 + num; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    set<long long> s;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            s.insert(go(i));
            s.insert(go(n / i));
        }
    }
    for (auto u : s) {
        cout << u << ' ';
    }
    cout << endl;
    return 0;
}