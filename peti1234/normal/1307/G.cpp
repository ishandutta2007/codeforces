#include <bits/stdc++.h>

using namespace std;
const int c=55, sok=1e9;
int n, m, t[c][c], kezd, veg, tav[c], fel[c];
vector<int> sz[c], s[c], ert[c], pos[c];
vector<pair<long double, int> > sol;
void add(int a, int b, int c) {
    pos[a].push_back(sz[b].size()), pos[b].push_back(sz[a].size());
    sz[a].push_back(b), s[a].push_back(1), ert[a].push_back(c);
    sz[b].push_back(a), s[b].push_back(0), ert[b].push_back(-c);
}
void spec_dijkstra() {
    for (int i=1; i<=veg; i++) {
        tav[i]=sok, fel[i]=-1;
    }
    tav[kezd]=0;
    priority_queue<pair<int, int> > q;
    q.push({0, kezd});
    while(q.size()) {
        int kell=-q.top().first, id=q.top().second;
        q.pop();
        if (tav[id]==kell) {
            for (int i=0; i<sz[id].size(); i++) {
                int uj=sz[id][i], ss=s[id][i], pl=ert[id][i];
                if (ss) {
                    int ujtav=kell+pl;
                    if (ujtav<tav[uj]) {
                        tav[uj]=ujtav;
                        int visz=pos[id][i];
                        fel[uj]=visz;
                        q.push({-ujtav, uj});
                    }
                }
            }
        }
    }
}
int flow() {
    int ans=0, db=0;
    while (true) {
        spec_dijkstra();
        if (tav[veg]>=sok) {
            break;
        }
        ans+=tav[veg], db++;
        sol.push_back({ans, db});
        int x=veg;
        while(fel[x]!=-1) {
            int ki=sz[x][fel[x]];
            int inv=pos[x][fel[x]];
            s[x][fel[x]]++, s[ki][inv]--;
            x=ki;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    kezd=1, veg=n;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    flow();


    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        long double pl, ans=sok;
        cin >> pl;
        for (auto x:sol) {
            ans=min(ans, (x.first+pl)/x.second);
        }
        cout.precision(20);
        cout << ans << "\n";
    }
    return 0;
}