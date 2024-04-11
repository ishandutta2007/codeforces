#include <bits/stdc++.h>

using namespace std;
const int c=105;
int n, ans;
vector<int> sz[c];
int main()
{
    cin >> n;
    for (int i=1; i<=2*n; i++) {
        int x;
        cin >> x;
        sz[x].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int a=sz[i][0], b=sz[i][1], c=sz[j][0], d=sz[j][1];
            if (a>c) swap(a, c), swap(b, d);
            if (b>c) ans++;
            if (b>d) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}