#include <bits/stdc++.h>

using namespace std;
bool v[10];
int t[11];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        v[x]=true;
    }
    for (int i=1; i<=n; i++) {
        if (v[t[i]]) {
            cout << t[i] << " ";
        }
    }
    return 0;
}