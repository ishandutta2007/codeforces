#include <bits/stdc++.h>

using namespace std;
int n;
int t[2001];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    cout << n+1 << endl;
    for (int i=n; i>=1; i--) {
        int a=(15000+i)-(t[i]%10000);
        cout << 1 << " " << i << " " << a << endl;
        for (int j=1; j<=i; j++) {
            t[j]+=a;
        }
    }
    cout << 2 << " " << n << " " << 10000 << endl;
    return 0;
}