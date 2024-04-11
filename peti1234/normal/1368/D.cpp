#include <bits/stdc++.h>

using namespace std;
long long t[200002], db[22], n, sum;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        for (int j=0; j<22; j++) {
            if (x%2) db[j]++;
            x/=2;
        }
    }
    for (int i=0; i<22; i++) for (int j=1; j<=db[i]; j++) t[j]+=(1<<i);
    for (int i=1; i<=n; i++) sum+=t[i]*t[i];
    cout << sum << "\n";
    return 0;
}