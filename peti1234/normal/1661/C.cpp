#include <bits/stdc++.h>

using namespace std;
long long w, n, t[300005], maxi;
long long solve(long long x) {
    long long e=0, k=0;
    for (int i=1; i<=n; i++) {
        if (t[i]%2!=x%2) e++;
        k+=(x-t[i])/2;
    }
    if (k>e) {
        long long dif=(k-e+1)/3;
        k-=dif, e+=2*dif;
    }
    return max(2*e-1, 2*k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            maxi=max(maxi, t[i]);
        }
        cout << min(solve(maxi), solve(maxi+1)) << "\n";
        maxi=0;
    }
    return 0;
}