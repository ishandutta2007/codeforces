#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, x=0, y=0;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int s;
        cin >> s;
        if (s%2) x++;
        else y++;
    }
    y=y%2, x=x%4;
    if ((y==0 && (x==0 || x==3)) || (y==1 && (x==0 || x==1 || x==3))) cout << "Alice\n";
    else cout << "Bob\n";
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