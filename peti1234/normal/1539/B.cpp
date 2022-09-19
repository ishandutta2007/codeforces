#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, m, kom[c];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        kom[i]=kom[i-1]+(c-'a'+1);
    }
    for (int i=1; i<=m; i++) {
        int l, r;
        cin >> l >> r;
        cout << kom[r]-kom[l-1] << "\n";
    }
    return 0;
}