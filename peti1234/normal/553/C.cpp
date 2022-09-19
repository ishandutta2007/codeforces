#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, m, ki[2*c], mod=1e9+7, ans=(mod+1)/2;
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        unio(a, (c ? b : b+n));
        unio(a+n, (c ? b+n : b));
    }
    for (int i=1; i<=n; i++) {
        if (holvan(i)==holvan(i+n)) {
            ans=0;
        }
        if (holvan(i)==i) {
            ans=2*ans%mod;
        }
    }
    cout << ans << "\n";
    return 0;
}