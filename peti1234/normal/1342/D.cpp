#include <bits/stdc++.h>

using namespace std;
int n, k, t[200002], db[200002], x=1, m=1;
vector<int> sol[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    for (int i=1; i<=k; i++) cin >> db[i];
    for (int i=n; i>=1; i--) {
        int p=db[t[i]];
        while(x>1 && sol[x-1].size()<p) x--;
        while(sol[x].size()>=p) x++;
        m=max(m, x), sol[x].push_back(t[i]);
    }
    cout << m << "\n";
    for (int i=1; i<=m; i++) {
        cout << sol[i].size() << " ";
        for (int j=0; j<sol[i].size(); j++) cout << sol[i][j] << " ";
        cout << endl;
    }
    return 0;
}