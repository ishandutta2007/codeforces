#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> sz[100001];
long long sum;
int t[1000001];
int k[1000001];
bool q=true;
void dfs(int a)
{
    //cout << a << endl;
    if (t[a]!=-1) {
        k[a]=t[a];
    }
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        dfs(x);
        if (k[x]!=-1) {
            if (k[x]<t[a]) {
                q=false;
            }
            k[a]=min(k[a], k[x]);
        }
    }
}
void s(int a, int b)
{
    if (k[a]!=INT_MAX) {
        sum+=k[a]-b;
    }
    b=k[a];
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        s(x, b);
    }
}
int main()
{
    cin >> n;
    for (int i=2; i<=n; i++) {
        int a;
        cin >> a;
        sz[a].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        k[i]=INT_MAX;
    }
    dfs(1);
    if (!q) {
        cout << -1 << endl;
        return 0;
    }
    s(1, 0);
    cout << sum << endl;
    return 0;
}