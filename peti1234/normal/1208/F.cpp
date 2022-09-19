#include <bits/stdc++.h>

using namespace std;
const int k=21, c=(1<<k);
int n, ans, s, a[c], b[c], t[c];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> s;
        t[i]=s, b[s]=i;
        if (b[s]>a[s]) {
            swap(a[s], b[s]);
        }
    }
    for (int i=c-1; i>=1; i--) {
        for (int j=0; j<k; j++) {
            if (i&(1<<j)) {
                s=i-(1<<j);
                if (a[i]!=a[s]) b[s]=max(b[s], a[i]);
                if (b[s]>a[s]) {
                    swap(a[s], b[s]);
                }
                b[s]=max(b[s], b[i]);
            }
        }
    }
    for (int j=k-1; j>=0; j--) {
        bool jo=0;
        ans+=(1<<j);
        for (int i=1; i<=n; i++) {
            s=(ans|(t[i]))^t[i];
            if (b[s]>i) {
                jo=1;
            }
        }
        if (!jo) {
            ans-=(1<<j);
        }
    }
    cout << ans << "\n";
    return 0;
}