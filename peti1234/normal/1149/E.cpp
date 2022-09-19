#include <bits/stdc++.h>

using namespace std;
const int c=200002;
queue<int> q;
vector<int> sz[c], s[c], f[c];
long long n, m, be[c], me[c], t[c], xo[c], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> t[i], f[i].push_back(c);
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), s[b].push_back(a);
        be[a]++;
    }
    for (int i=1; i<=n; i++) if (!be[i]) q.push(i);
    while(q.size()>0) {
        int id=q.front(), pr=0;
        q.pop();
        sort(f[id].begin(), f[id].end());
        for (int i=0; i<f[id].size(); i++) {
            if (f[id][i]-pr>1) {
                pr++;
                xo[pr]^=t[id];
                me[id]=pr;
                break;
            }
            pr=f[id][i];
        }
        for (int i=0; i<s[id].size(); i++) {
            int x=s[id][i];
            f[x].push_back(me[id]);
            be[x]--;
            if (!be[x]) q.push(x);
        }
    }
    for (int i=1; i<=n; i++) {
        if (xo[i]) maxi=i;
    }
    if (!maxi) {
        cout << "LOSE\n";
    } else {
        cout << "WIN\n";
        for (int i=1; i<=n; i++) {
            if (me[i]==maxi && (t[i]^xo[me[i]])<t[i]) {
                for (int j=0; j<sz[i].size(); j++) {
                    int x=sz[i][j];
                    if (xo[me[x]]) {
                        t[x]^=xo[me[x]];
                        xo[me[x]]=0;
                    }
                }
                t[i]^=xo[maxi];
                xo[maxi]=0;
                break;
            }
        }
        for (int i=1; i<=n; i++) {
            cout << t[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}