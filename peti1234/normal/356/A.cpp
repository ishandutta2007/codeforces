#include <bits/stdc++.h>

using namespace std;
int n, m;
set<int> t;
int kov[300002];
int fix[300001];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        t.insert(i);
    }
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (auto j=t.lower_bound(a); j!=t.end() && *j<=b;) {
            if (*j!=c) {
                fix[*j]=c;
                j=t.erase(j);
            }
            else {
                j++;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << fix[i] << " ";
    }
    return 0;
}