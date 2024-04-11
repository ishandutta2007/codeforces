#include <bits/stdc++.h>

using namespace std;
int w, n, t[105];
void solve(int st) {
    int pos=st;
    for (int i=st; i<=n; i++) {
        if (t[i]<t[pos]) {
            pos=i;
        }
    }
    for (int i=pos; i>st; i--) {
        swap(t[i], t[i-1]);
    }
    int maxi=max(pos, st+1);
    if (maxi<n) {
        solve(maxi);
    }
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        solve(1);
        for (int i=1; i<=n; i++) {
            cout << t[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}