#include <bits/stdc++.h>

using namespace std;
long long n, m;
int t[200001];
long long q=1;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> t[i];
    if (n>m) {
        cout << 0 << endl;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            q*=abs(t[j]-t[i]);
            q%=m;
        }
    }
    cout << q << endl;
    return 0;
}