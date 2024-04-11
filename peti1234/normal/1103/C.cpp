#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int n, m, k, szint[c], fel[c], db[c];
vector<int> sz[c];
bool v[c];
void ut(int a, int b) {
    cout << a << " ";
    while (a!=b) {
        a=fel[a];
        cout << a << " ";
    }
    cout << "\n";
}
void dfs(int a) {
    if (szint[a]*k>=n) {
        cout << "PATH\n";
        cout << szint[a] << "\n";
        ut(a, 1);
        exit(0);
    }
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            db[a]++;
            szint[x]=szint[a]+1;
            fel[x]=a;
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);
    cout << "CYCLES\n";
    for (int i=1; i<=n; i++) {
        if (k && db[i]==0) {
            k--;
            int a=0, b=0;
            for (auto x:sz[i]) {
                if (x!=fel[i]) {
                    if (!a) a=x;
                    else b=x;
                }
            }
            if (szint[a]<szint[b]) swap(a, b);
            int x=szint[i], y=szint[a], z=szint[b];
            if ((x-y+1)%3) {
                cout << x-y+1 << "\n";
                ut(i, a);
            } else if ((x-z+1)%3) {
                cout << x-z+1 << "\n";
                ut(i, b);
            } else {
                cout << y-z+2 << "\n";
                cout << i << " ";
                ut(a, b);
            }
        }
    }
    return 0;
}