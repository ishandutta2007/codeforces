#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int n, ans, t[c], kis[c], nagy[c], sok=1e9+1;
void solve() {
    int pos=1;
    for (int i=1; i<=n; i++) {
        if (t[i]>t[pos]) {
            pos=i;
        }
    }
    long long x=0, y=0;
    for (int i=n; i>pos; i--) {
        if (t[i]>x) x=t[i];
        else if (t[i]>y) y=t[i];
        else x=sok, y=sok;
        kis[i]=y, nagy[i]=x;
    }
    x=0, y=0;
    for (int i=1; i<=pos; i++) {
        if (t[i]<y) return;
        else if (t[i]>x) x=t[i];
        else y=t[i];
    }
    for (int i=pos+1; i<=n; i++) {
        if (i>pos+1) {
            int a=t[i-1], b=t[i];
            if (x<y) {
                if (a<x) x=a;
                else if (a>y) y=a;
                else return;
            } else {
                if (a>y && (a>x || b>a)) y=a;
                else x=a;
            }
        }
        if (t[i]>y && ((t[i]>nagy[i+1] && x>kis[i+1]) || (t[i]>kis[i+1] && x>nagy[i+1]))) {
            ans++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    solve();
    reverse(t+1, t+n+1);
    solve();
    cout << ans << "\n";
    return 0;
}