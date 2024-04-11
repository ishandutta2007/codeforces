#include <bits/stdc++.h>

using namespace std;
long long w, n, sum, odb, omini, edb, emini, mini, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        odb=edb=sum=0;
        omini=emini=1e9;
        mini=1e18;
        for (int i=1; i<=n; i++) {
            cin >> x;
            sum+=x;
            if (i%2) {
                odb++;
                omini=min(omini, x);
            } else {
                edb++;
                emini=min(emini, x);
            }
            mini=min(mini, sum+(n-odb)*omini+(n-edb)*emini);
        }
        cout << mini << "\n";
    }
    return 0;
}
/*
1
3
2 3 1
*/