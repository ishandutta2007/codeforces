#include <bits/stdc++.h>

using namespace std;
int w, n, k, sm, x, db;
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, sum=0;
        sm=(n-1)/2*k, db=n/2;
        for (int i=1; i<=sm; i++) {
            cin >> x;
        }
        for (int i=1; i<=k; i++) {
            cin >> x; sum+=x;
            for (int j=1; j<=db; j++) cin >> x;
        }
        cout << sum << "\n";
    }
    return 0;
}