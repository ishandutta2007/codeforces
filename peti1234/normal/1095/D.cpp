#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, s[c], t[c], cnt;
void dfs(int a) {
    cout << a << " ";
    cnt++;
    if (cnt==n) {
        return;
    }
    int x=s[a], y=t[a];
    if (s[x]==y ||t[x]==y) {
        dfs(x);
    } else {
        dfs(y);
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> s[i] >> t[i];
    }
    if (n==3) {
        cout << "1 2 3\n";
        return 0;
    }
    dfs(1);
    cout << "\n";
    return 0;
}