#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, szint[c], ert[c], ans[c], n2;
vector<int> sz[c], lvl[c];
bool v[c], spec[c];
priority_queue<pair<int, int> > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> spec[i];
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (spec[i]) {
            q.push({0, i});
        }
    }
    while (q.size()>0) {
        int id=q.top().second, tav=-q.top().first;
        q.pop();
        if (!v[id]) {
            v[id]=1;
            szint[id]=tav;
            //cout << "szint " << id << " " << tav << "\n";
            lvl[tav].push_back(id);
            n2=max(n2, tav);
            for (auto x:sz[id]) {
                if (!v[x]) {
                    q.push({-tav-1, x});
                }
            }
        }
    }
    for (int i=0; i<=n2; i++) {
        for (auto x:lvl[i]) {
            for (auto y:sz[x]) {
                if (szint[y]==i) {
                    q.push({0, x});
                    break;
                }
            }
        }
        if (q.size()>0) {
            for (int i=1; i<=n; i++) {
                v[i]=0, ert[i]=c;
            }
            for (int p=i; p<=n2; p++) {
                while (q.size()>0) {
                    int id=q.top().second, tav=-q.top().first;
                    q.pop();
                    if (!v[id]) {
                        v[id]=1;
                        ert[id]=tav;
                        for (auto x:sz[id]) {
                            if (!v[x] && szint[id]==szint[x]) {
                                q.push({-tav-1, x});
                            }
                        }
                    }
                }
                for (auto x:lvl[p]) {
                    for (auto y:sz[x]) {
                        if (szint[y]==szint[x]+1) {
                            q.push({min(0, -ert[x]+1), y});
                        }
                    }
                }
            }
            for (int j=1; j<=n; j++) {
                if (ert[j]==0 && !ans[j]) {
                    ans[j]=2*szint[j]-i+1;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (!ans[i]) {
            ans[i]=szint[i];
        } else {
            ans[i]--;
        }
        cout << ans[i] << " ";
    }
    return 0;
}