#include <bits/stdc++.h>

using namespace std;

const int N = 100010;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long m;
    cin >> n >> m;
    long long cur = 0;
    int numN = 0;
    while (cur < m && numN < n) {
        cur += numN;
        numN++;
    }
    cout << max(0ll, 1ll * n - m * 2) << " " << n - numN << endl;
    return 0;
}