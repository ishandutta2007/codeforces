#include <bits/stdc++.h>

using namespace std;
const long long c=400002, k=18;
long long dp[c][k+1], n, m, mod=998244353;
vector<int> sz[c], s[c];
bool v[c][k+1];
priority_queue<pair<long long, pair<int, int> > > q;
void add(int a, int b, int x) {
    sz[a].push_back(b), s[a].push_back(x);
}
void pb(long long a, int b, int c) {
    c=min(c, 18);
    if (!v[b][c]) q.push({-a, {b, c}});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        add(i, i+n, c), add(i+n, i, c);
    }
    add(2*n, n, 0);
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        add(a, b, 1);
        add(b+n, a+n, 1);
    }
    pb(0, 1, 0);
    while(q.size()>0) {
        long long tav=-q.top().first, id=q.top().second.first, db=q.top().second.second;
        //cout << id << " " << db << " " << tav << endl;
        q.pop();
        if (!v[id][db]) {
            v[id][db]=1;
            dp[id][db]=tav;
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i], y=s[id][i];
                if (y==c) {
                    pb(tav+y, x, db+1);
                } else {
                    pb(tav+y, x, db);
                }
            }
        }
    }
    if (v[n][k-1]) {
        int mini=1e9;
        for (int i=0; i<k; i++) {
            if (v[n][i]) {
                int x=dp[n][i]%c;
                mini=min(mini, (1<<i)+x-1);
            }
        }
        cout << mini << "\n";
    } else {
        long long sum=0, po=1, x=dp[n][k];
        while(x>=c) {
            x-=c, sum+=po;
            po*=2, po%=mod, sum%=mod;
        }
        sum+=x;
        cout << sum%mod << "\n";
    }
    return 0;
}
/*
4 4
1 2
2 3
3 4
4 1
*/