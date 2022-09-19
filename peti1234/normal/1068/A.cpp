#include <bits/stdc++.h>

using namespace std;
long long n, m, l, k;
int main()
{
    cin >> n >> m >> l >> k;
    k+=l;
    if (k%m) {
        k-=k%m, k+=m;
    }
    if (k>n) cout << -1 << "\n";
    else cout << k/m << "\n";
    return 0;
}