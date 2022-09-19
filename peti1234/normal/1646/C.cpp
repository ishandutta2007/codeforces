#include <bits/stdc++.h>

using namespace std;
long long fakt[16], mini, w, n;
int main()
{
    fakt[0]=1;
    for (int i=1; i<=15; i++) fakt[i]=fakt[i-1]*i;
    cin >> w;
    while (w--) {
        cin >> n;
        mini=__builtin_popcountll(n);
        for (int mask=0; mask<(1<<16); mask+=8) {
            long long sum=0;
            for (int j=0; j<16; j++) {
                if (mask & (1<<j)) {
                    sum+=fakt[j];
                }
            }
            long long ert=__builtin_popcount(mask)+__builtin_popcountll(n-sum);
            if (sum<=n) {
                mini=min(mini, ert);
            }
        }
        cout << mini << "\n";
    }
    return 0;
}