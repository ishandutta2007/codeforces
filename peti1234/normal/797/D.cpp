#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, bal[c], jobb[c], ert[c], ans;
bool v[c];
set<int> s;
void dfs(int a, int kis, int nagy) {
    if (a==-1 || kis>nagy) {
        return;
    }
    if (kis<=ert[a] && ert[a]<=nagy) {
        s.insert(ert[a]);
    }
    dfs(bal[a], kis, min(nagy, ert[a]-1));
    dfs(jobb[a], max(kis, ert[a]+1), nagy);
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> ert[i] >> bal[i] >> jobb[i];
        if (bal[i]!=-1) v[bal[i]]=1;
        if (jobb[i]!=-1) v[jobb[i]]=1;
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i, 0, 2e9);
        }
    }
    for (int i=1; i<=n; i++) {
        if (s.count(ert[i])) {
            ans++;
        }
    }
    cout << n-ans << "\n";
    return 0;
}