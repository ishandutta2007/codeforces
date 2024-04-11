#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, m, a, b, x, y, t[c][c], uj[c][c], kezd[c], veg[c];
long long kom[c][c], mini[c][c];
bool v[c][c];
priority_queue<pair<long long, pair<int, int> > > q;
vector<pair<long long, pair<int, int> > > sol;
void solve(int h, int p) {
    deque<int> q;
    for (int i=h; i>=1; i--) {
        while(q.size()>0 && kezd[i]<kezd[q.back()]) q.pop_back();
        if (q.size()>0 && q.front()==i+p) q.pop_front();
        q.push_back(i);
        veg[i]=kezd[q.front()];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> a >> b, x=n-a+1, y=m-b+1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
            kom[i][j]=t[i][j]+kom[i-1][j]+kom[i][j-1]-kom[i-1][j-1];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            kezd[j]=t[i][j];
        }
        solve(m, b);
        for (int j=1; j<=y; j++) {
            uj[i][j]=veg[j];
        }
    }
    for (int j=1; j<=y; j++) {
        for (int i=1; i<=n; i++) {
            kezd[i]=uj[i][j];
        }
        solve(n, a);
        for (int i=1; i<=x; i++) {
            mini[i][j]=veg[i];
        }
    }
    for(int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            long long sum=kom[i+a][j+b]-kom[i][j+b]-kom[i+a][j]+kom[i][j], mi=mini[i+1][j+1];
            q.push({mi*a*b-sum, {-i-1, -j-1}});
        }
    }
    while(q.size()>0) {
        int fi=-q.top().second.first, se=-q.top().second.second;
        if (!v[fi][se]) {
            sol.push_back(q.top());
            for (int i=max(1, fi-a+1); i<=min(n, fi+a-1); i++) {
                for (int j=max(1, se-b+1); j<=min(m, se+b-1); j++) {
                    v[i][j]=true;
                }
            }
        }
        q.pop();
    }
    cout << sol.size() << "\n";
    for (auto i:sol) {
        cout << -i.second.first << " " << -i.second.second << " " << -i.first << "\n";
    }
    return 0;
}