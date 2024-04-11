#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long n, m, k;
long double db[c], sum, fakt[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    db[0]=1, fakt[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i;
    }
    for (int i=1; i<=k; i++) {
        db[i]=db[i-1]*(k-i+1)/(m-i+1);
    }
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            sum+=fakt[n]*fakt[n]/fakt[i]/fakt[n-i]/fakt[j]/fakt[n-j]*db[n*(i+j)-i*j];
        }
    }
    cout.precision(20);
    cout << min((long double)1e99, sum) << "\n";
    return 0;
}