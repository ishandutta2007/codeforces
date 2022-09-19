#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, m, szint[c];
long long dif[c], sum, osum, esum;
vector<int> sz[c];
bool v[c], pkor;
void dfs(int a) {
    v[a]=true;
    if (szint[a]%2) {
        osum+=dif[a];
    } else {
        esum+=dif[a];
    }
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            dfs(x);
        }
        if ((szint[a]%2) == szint[x]%2) {
            pkor=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            dif[i]-=x;
        }
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            dif[i]+=x;
            sum+=dif[i];
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        cout << (sum%2==0 && (pkor || (osum==esum)) ? "YES" : "NO") << "\n";

        sum=0, osum=0, esum=0, pkor=0;
        for (int i=1; i<=n; i++) {
            dif[i]=0, v[i]=0, szint[i]=0;
            sz[i].clear();
        }
    }
    return 0;
}
/*
1
4 4
5 8 6 6
-3 1 15 4
1 2
1 4
3 2
3 4
*/