#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, k, o, e, mini, kor, szint[c], f[c];
vector<int> sz[c];
bool v[c];
void dfs(int a)
{
    if (szint[a]%2) o++;
    else e++;
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], q=szint[a]-szint[x];
        if (!v[x]) szint[x]=szint[a]+1, f[x]=a, dfs(x);
        else if (x!=f[a] && q>0 && q+1<kor) mini=a, kor=q+1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k, kor=n+1;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    if (m<n) {
        cout << 1 << "\n", k++, k/=2;
        if (o>e) {for (int i=1; i<=n; i++) if (szint[i]%2 && k) cout << i << " ", k--;}
        else {for (int i=1; i<=n; i++) if (szint[i]%2==0 && k) cout << i << " ", k--;}
    } else if (kor>k) {
        cout << 1 << "\n", k++, k/=2;
        while(k) {cout << mini << " ", mini=f[mini], mini=f[mini], k--;}
    } else {
        cout << 2 << "\n" << kor << "\n";
        for (int i=1; i<=kor; i++) cout << mini << " ", mini=f[mini];
    }
    return 0;
}
/*
4 3 4
1 2 2 3 3 4
*/