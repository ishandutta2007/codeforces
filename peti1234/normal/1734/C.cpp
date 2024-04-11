#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n;
    long long ans=0;
    string a, b;
    cin >> n >> b;
    for (int i=0; i<n; i++) a+="1";
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j+=i) {
            char x=a[j-1], y=b[j-1];
            if (x=='1' && y=='0') ans+=i, a[j-1]='0';
            if (y=='1') break;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}