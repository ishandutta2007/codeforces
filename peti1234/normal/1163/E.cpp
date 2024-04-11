#include <bits/stdc++.h>

using namespace std;
const int c=(1<<18);
int n, t[c], ans, db, ert;
bool v[c];
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    v[0]=1;
    for (int i=1; i<=n; i++) {
        while (t[i]>=(1<<db)) {
            db++;
        }
        if (!v[t[i]]) {
            for (int j=0; j<(1<<db); j++) {
                if (v[j]) {
                    v[j^t[i]]=1;
                }
            }
            sz.push_back(t[i]);
        }
        if (sz.size()==db) {
            ans=db;
        }
    }
    cout << ans << "\n";
    cout << ert << " ";
    for (int i=1; i<(1<<ans); i++) {
        ert^=sz[__builtin_ctz(i)];
        cout << ert << " ";
    }
    cout << "\n";
    return 0;
}