#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long n, m, dp[c][4];
vector<int> sz[c], s[c];
bool v[c][4];
priority_queue<pair<long long, pair<int, int> > > q;
void add(long long a, int b, int c) {
    q.push({-a, {b, c}});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        sz[a].push_back(b), sz[b].push_back(a);
        s[a].push_back(c), s[b].push_back(c);
    }
    add(0, 1, 0);
    while (q.size()>0) {
        long long tav=-q.top().first, a=q.top().second.first, b=q.top().second.second;
        q.pop();
        if (!v[a][b]) {
            v[a][b]=1;
            dp[a][b]=tav;
            for (int i=0; i<sz[a].size(); i++) {
                int x=sz[a][i], y=s[a][i];
                add(tav+y, x, b);
                if (b%2==0) {
                    add(tav+2*y, x, b+1);
                }
                if (b<2) {
                    add(tav, x, b+2);
                }
            }
        }
    }
    for (int i=2; i<=n; i++) {
        cout << min(dp[i][0], dp[i][3]) << " ";
    }
    cout << "\n";
    return 0;
}