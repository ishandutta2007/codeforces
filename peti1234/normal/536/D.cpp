#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int n, m, bcs, bal[c], invbal[c], jcs, jobb[c], invjobb[c];
long long ert[c], distbal[c], distjobb[c], dp[c][c][2], sum, ans;
vector<int> sz[c], s[c], sor;
bool v[c];
priority_queue<pair<long long, int> > q;
void dijkstra(int kezd) {
    q.push({0, kezd});
    while (q.size()>0) {
        long long tav=-q.top().first;
        int id=q.top().second;
        q.pop();
        if (!v[id]) {
            v[id]=1;
            sor.push_back(id);
            distbal[id]=tav;
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i];
                long long y=tav+s[id][i];
                if (!v[x]) {
                    q.push({-y, x});
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> bcs >> jcs;
    for (int i=1; i<=n; i++) {
        cin >> ert[i];
    }
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back(b), sz[b].push_back(a);
        s[a].push_back(c), s[b].push_back(c);
    }
    dijkstra(jcs);
    for (int i=1; i<=n; i++) {
        v[i]=0;
        swap(distbal[i], distjobb[i]);
    }
    for (int i=0; i<n; i++) {
        jobb[i+1]=sor[i];
        invjobb[sor[i]]=i+1;
    }
    sor.clear();
    dijkstra(bcs);
    for (int i=1; i<=n; i++) {
        v[i]=0;
    }
    for (int i=0; i<n; i++) {
        bal[i+1]=sor[i];
        invbal[sor[i]]=i+1;
    }
    sor.clear();

    for (int a=n; a>=1; a--) {
        for (int b=n; b>=1; b--) {
            for (int s=0; s<2; s++) {
                if (s==0) {
                    if (invjobb[bal[a]]<b) {
                        dp[a][b][s]=dp[a+1][b][s];
                    } else {
                        long long maxi=dp[a+1][b][s];
                        if (distbal[bal[a]]!=distbal[bal[a+1]]) {
                            maxi=max(maxi, -dp[a+1][b][!s]);
                        }
                        dp[a][b][s]=maxi+ert[bal[a]];
                    }
                } else {
                    if (invbal[jobb[b]]<a) {
                        dp[a][b][s]=dp[a][b+1][s];
                    } else {
                        long long maxi=dp[a][b+1][s];
                        if (distjobb[jobb[b]]!=distjobb[jobb[b+1]]) {
                            maxi=max(maxi, -dp[a][b+1][!s]);
                        }
                        dp[a][b][s]=maxi+ert[jobb[b]];
                    }
                }
                //cout << a << " " << b << " " << s << " " << dp[a][b][s] << "\n";
            }
        }
    }

    ans=dp[1][1][0];

    if (ans>0) {
        cout << "Break a heart\n";
    }
    if (ans<0) {
        cout << "Cry\n";
    }
    if (ans==0) {
        cout << "Flowers\n";
    }

    return 0;
}