#include <bits/stdc++.h>

using namespace std;
const int c=500005;
bool v[c];
void solve() {
    int n;
    string s;
    cin >> n >> s;
    n*=2;
    int ans=0, ert=0;
    for (auto x:s) {
        if (x=='(') {
            ert++;
            if (!v[ert]) ans++, v[ert]=1;
        } else {
            ert--;
            v[ert+2]=0;
        }
    }
    cout << ans << "\n";
    for (int i=0; i<=n; i++) v[i]=0;
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