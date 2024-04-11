#include <bits/stdc++.h>

using namespace std;
const int c=5005;
int n, k, t[c], ans[c];
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=k; i++) {
        ans[i]=i;
    }
    for (int i=k+1; i<=n; i++) {
        for (int j=1; j<i; j++) {
            if (t[i]==t[j]) {
                v[ans[j]]=1;
            }
        }
        for (int j=1; j<=k; j++) {
            if (!v[j]) {
                ans[i]=j;
            }
            v[j]=0;
        }
        if (!ans[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}