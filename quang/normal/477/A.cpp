#include <bits/stdc++.h>

using namespace std;

long long a, b ,MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> a >> b;
    long long p1 = (a * (a + 1) / 2) % MOD;
    p1 = (p1 * b) % MOD;
    p1 = (p1 + a) % MOD;
    long long p2 = ((b -1 ) *b / 2)% MOD;
    p1 = (p1 * p2) % MOD;
    cout << p1;
    return 0;
}