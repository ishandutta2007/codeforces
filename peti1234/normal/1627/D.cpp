#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, ans;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        v[x]=1;
    }
    for (int i=1; i<c; i++) {
        if (v[i]) continue;
        int s=0;
        for (int j=i; j<c; j+=i) {
            if (v[j]) {
                if (i==2) {}
                s=__gcd(s, j);
            }
        }
        if (s==i) ans++;
    }

    cout << ans << "\n";
    return 0;
}