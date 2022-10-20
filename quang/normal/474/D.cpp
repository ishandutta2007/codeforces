#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100100;
const long long MOD = 1000000007;

int t, k;
long long sl[N];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> t >> k;
    sl[0] = 1;
    for(int i = 1; i < N; i++) {
        int tr = i - k;
        sl[i] = sl[i - 1];
        if(tr >= 0)
            sl[i] = (sl[i] + sl[tr]) % MOD;
    }
    for(int i = 1; i < N; i++)
        sl[i] = (sl[i] + sl[i - 1]) % MOD;
    for(int i = 1; i <= t; i++) {
        int a, b;
        cin >> a >> b;
        long long res = sl[b] - sl[a - 1];
        cout << (res + MOD) % MOD << endl;
    }
    return 0;
}