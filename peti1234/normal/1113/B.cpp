#include <bits/stdc++.h>

using namespace std;
int n, sum, mini=100, maxi;
bool v[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        sum+=x, mini=min(mini, x);
        v[x]=true;
    }
    for (int i=1; i<=100; i++) {
        if (v[i]) {
            for (int j=1; j<=i; j++) {
                if (i%j==0) {
                    maxi=max(maxi, i+mini-mini*j-i/j);
                }
            }
        }
    }
    cout << sum-maxi << "\n";
    return 0;
}
/*
2
1 4
*/