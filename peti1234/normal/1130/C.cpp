#include <bits/stdc++.h>

using namespace std;
bool v[52][52];
vector<pair<int, int> > k;
int mini=INT_MAX;
int n;
int a, b, c, d;
void dfs(int x, int y, int s)
{
    v[x][y]=true;
    if (s==0) {
        k.push_back({x, y});
    }
    if (!v[x-1][y]) {
        dfs(x-1, y, s);
    }
    if (!v[x+1][y]) {
        dfs(x+1, y, s);
    }
    if (!v[x][y-1]) {
        dfs(x, y-1, s);
    }
    if (!v[x][y+1]) {
        dfs(x, y+1, s);
    }
    if (s==1) {
        for (int i=0; i<k.size(); i++) {
            int sum=0;
            int fi=k[i].first;
            int se=k[i].second;
            sum=(x-fi)*(x-fi)+(y-se)*(y-se);
            mini=min(mini, sum);
        }
    }
}
int main()
{
    cin >> n;
    cin >> a >> b >> c >> d;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char x;
            cin >> x;
            if (x=='1') {
                v[i][j]=true;
            }
        }
    }
    for (int i=0; i<=n+1; i++) {
        v[i][0]=true;
        v[i][n+1]=true;
        v[0][i]=true;
        v[n+1][i]=true;
    }
    dfs(a, b, 0);
    dfs(c, d, 1);
    cout << mini << endl;
    return 0;
}