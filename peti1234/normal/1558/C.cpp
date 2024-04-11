#include <bits/stdc++.h>

using namespace std;
const int c=2055;
int w, n, t[c], inv[c], r;
void p(int a) {
    cout << a << " ";
    for (int i=1; i<=a/2; i++) {
        swap(t[i], t[a+1-i]);
        swap(inv[t[i]], inv[t[a+1-i]]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            inv[t[i]]=i;
            if ((t[i]+i)%2) {
                r=1;
            }
        }
        if (r) {
            cout << -1 << "\n";
            r=0;
            continue;
        }
        cout << n/2*5 << "\n";
        for (int i=n-1; i>=2; i-=2) {
            p(inv[i+1]);
            p(inv[i]-1);
            p(inv[i]+1);
            p(3);
            p(i+1);
        }
        cout << "\n";
    }
    return 0;
}