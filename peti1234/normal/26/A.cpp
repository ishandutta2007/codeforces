#include <bits/stdc++.h>

using namespace std;
bool pr[3001];
int n, ans;
int main()
{
    cin >> n;
    for (int i=2; i<=n; i++) {
        if (!pr[i]) {
            for (int j=2*i; j<=n; j+=i) pr[j]=1;
        }
    }
    for (int i=1; i<=n; i++) {
        int db=0;
        for (int j=2; j<n; j++) if (!pr[j] && (i%j)==0) db++;
        if (db==2) ans++;
    }
    cout << ans << "\n";
    return 0;
}