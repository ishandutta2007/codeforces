#include <bits/stdc++.h>

using namespace std;
int t[101], n, db;
bool v[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            db++;
            for (int j=1; j<=n; j++) {
                if (t[j]%t[i]==0) {
                    v[j]=true;
                }
            }
        }
    }
    cout << db << "\n";
    return 0;
}