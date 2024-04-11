#include <bits/stdc++.h>

using namespace std;
const int c=100005;
vector<int> sz[c], s[c];
bool v[c];
int n;
void pb(int a, int b)
{
    sz[a].push_back(b);
}
void solve(int a)
{
    v[a]=true;
    cout << a << " ";
    for (int i=0; i<s[a].size(); i++) {
        int x=s[a][i];
        if (!v[x]) {
            solve(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n-2; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pb(a, b), pb(b, a), pb(a, c), pb(c, a), pb(b, c), pb(c, b);
    }
    for (int i=1; i<=n; i++) {
        sort(sz[i].begin(), sz[i].end());
        int si=sz[i].size();
        for (int j=1; j<si; j++) {
            int x=sz[i][j];
            if (x==sz[i][j-1]) {
                s[i].push_back(x);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (s[i].size()==0) {
            cout << i << " ";
            int a=sz[i][0], b=sz[i][1];
            if (s[a].size()==1 && !v[a]) {
                solve(a);
            } else if (!v[b]) {
                solve(b);
            }
        }
    }
    return 0;
}