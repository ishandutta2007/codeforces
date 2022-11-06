#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];

bool e[MAXN + 1];

bool viz[MAXN + 1];

int fr[MAXN + 1];

struct Data {
    int nod;
    bool operator <(const Data &other) const {
        if(fr[nod] == fr[other.nod])
            return nod < other.nod;
        return fr[nod] < fr[other.nod];
    }
};

multiset <Data> q[2];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, x, y, nod;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> e[i];
    }
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        x++;
        y++;
        g[y].push_back(x);
        fr[x]++;
    }
    for(i = 1; i <= n; i++) {
        q[e[i]].insert({i});
    }
    int ans = 0, ind = 0;
    while(ind < n) {
        while(!q[0].empty() && fr[q[0].begin() -> nod] == 0) {
            ind++;
            nod = q[0].begin() -> nod;
            for(auto it : g[nod]) {
                q[e[it]].erase(q[e[it]].find({it}));
                fr[it]--;
                q[e[it]].insert({it});
            }
            q[0].erase(q[0].find({nod}));
        }
        if(!q[1].empty()) {
            ans++;
            while(!q[1].empty() && fr[q[1].begin() -> nod] == 0) {
                ind++;
                nod = q[1].begin() -> nod;
                for(auto it : g[nod]) {
                    q[e[it]].erase(q[e[it]].find({it}));
                    fr[it]--;
                    q[e[it]].insert({it});
                }
                q[1].erase(q[1].find({nod}));
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}