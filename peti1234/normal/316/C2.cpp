#include <bits/stdc++.h>

using namespace std;
const int c=82, k=c*c;
int n, m, t[c][c], kezd, veg, tav[k], fel[k];
vector<int> sz[k], s[k], ert[k], pos[k];
void add(int a, int b, int c) {
    pos[a].push_back(sz[b].size()), pos[b].push_back(sz[a].size());
    sz[a].push_back(b), s[a].push_back(1), ert[a].push_back(c);
    sz[b].push_back(a), s[b].push_back(0), ert[b].push_back(-c);
}
int cs(int a, int b) {
    return (a-1)*m+b;
}

void spec_dijkstra() {
    for (int i=1; i<=veg; i++) {
        tav[i]=k, fel[i]=0;
    }
    tav[kezd]=0;
    priority_queue<pair<int, int> > q;
    q.push({0, kezd});
    while(q.size()) {
        if (fel[veg]) break;
        int kell=-q.top().first, id=q.top().second;
        //cout << "dijkstra " << id << " " << kell << " " << sz[id].size() << endl;
        q.pop();
        if (tav[id]==kell) {
            for (int i=0; i<sz[id].size(); i++) {
                int uj=sz[id][i], ss=s[id][i], pl=ert[id][i];
                //cout << "el " << uj << " " << ss << " " << pl << endl;
                if (ss) {
                    int ujtav=kell+pl;
                    if (ujtav<tav[uj]) {
                        tav[uj]=ujtav;
                        fel[uj]=id;
                        q.push({-ujtav, uj});
                    }
                }
            }
        }
    }
}
int flow() {
    int ans=0;
    for (int i=1; i<=(n*m)/2; i++) {
        spec_dijkstra();
        ans+=tav[veg];
        int x=veg;
        //cout << "ujut ";
        while(fel[x]) {
            //cout << x << " ";
            int ki=fel[x];
            for (int i=0; i<sz[x].size(); i++) {
                if (sz[x][i]==ki) {
                    int inv=pos[x][i];
                    s[x][i]++, s[ki][inv]--;
                }
            }
            x=ki;
        }
        //cout << endl;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m, kezd=n*m+1, veg=n*m+2;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x=cs(i, j), y=t[i][j];
            if ((i+j)%2) {
                add(kezd, x, 0);
                if (i>1) {
                    add(x, cs(i-1, j), 1-(y==t[i-1][j]));
                }
                if (j>1) {
                    add(x, cs(i, j-1), 1-(y==t[i][j-1]));
                }

                if (i<n) {
                    add(x, cs(i+1, j), 1-(y==t[i+1][j]));
                }

                if (j<m) {
                    add(x, cs(i, j+1), 1-(y==t[i][j+1]));
                }

            } else {
                add(x, veg, 0);
            }
        }
    }
    int ans=flow();
    cout << ans << endl;
    return 0;
}
/*
1 2
1 1
*/