#include <bits/stdc++.h>

using namespace std;
const int c=5002;
int n, m, ans[c];
bool v[c], kor=0;
vector<int> sz[c];
void dfs(int a) {
    for (int x:sz[a]) {
        if (!v[x]) {
            v[x]=1;
            dfs(x);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        ans[i]=1+(a>b);
    }
    for (int i=1; i<=n; i++) {
        dfs(i);
        if (v[i]) {
            kor=1;
        }
        for (int j=1; j<=n; j++) {
            v[j]=0;
        }
    }
    if (!kor) {
        cout << 1 << "\n";
        for (int i=1; i<=m; i++) {
            cout << 1 << " ";
        }
    }
    else {
        cout << 2 << "\n";
        for (int i=1; i<=m; i++) {
            cout << ans[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}