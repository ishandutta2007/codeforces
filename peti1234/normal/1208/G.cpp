#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int n, k;
long long sum;
vector<int> sz, phi(c);
void solve(int n) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int main()
{
    cin >> n >> k;
    if (k==1) {
        cout << 3 << "\n";
        return 0;
    }
    solve(n);
    for (int i=1; i<=n; i++) {
        sum+=phi[i];
        sz.push_back(phi[i]);
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<n-k-2; i++) {
        sum-=sz[i];
    }
    cout << sum << "\n";
    return 0;
}