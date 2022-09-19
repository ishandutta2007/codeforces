#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, x, y, ans=0;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    for (int i=n-x; i<n; i++) {
        if ((s[i]=='1') != (i+y+1==n)) ans++;
    }
    cout << ans << "\n";
    return 0;
}