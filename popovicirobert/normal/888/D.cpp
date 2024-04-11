#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

const int MAXN = (int) 1e5;

int prod[5];

inline long long check(int n, int k) {
    int i;
    long long tot = 1;
    for(i = n - k + 1; i <= n; i++) {
        tot *= i;
    }
    for(i = 1; i <= k; i++)
        tot /= i;
    return 1LL * prod[k] * tot;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    long long ans = 0;
    prod[0] = 1;
    prod[1] = 0;
    prod[2] = 1;
    prod[3] = 2;
    prod[4] = 9;
    for(i = 0; i <= k; i++) {
        ans += check(n, i);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}