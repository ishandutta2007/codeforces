#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[MAXN + 1];

pair <int, int> edge[MAXN + 1];
int deg[MAXN + 1];

struct Data {
    int nod;
    bool operator <(const Data &other) const {
        if(deg[nod] == deg[other.nod])
            return nod < other.nod;
        return deg[nod] < deg[other.nod];
    }
};

multiset <Data> mst;
map < pair <int, int>, bool > mp;

int sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, x, y, k;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        edge[i] = {x, y};
        deg[x]++;
        deg[y]++;
    }
    for(i = 1; i <= n; i++) {
        mst.insert({i});
    }
    for(i = m; i >= 1; i--) {
        while(mst.size() && deg[mst.begin() -> nod] < k) {
            int nod = mst.begin() -> nod;
            mst.erase(mst.begin());
            deg[nod] = 0;
            for(auto it : g[nod]) {
                if(deg[it] > 0 && mp[{min(nod, it), max(nod, it)}] == 0) {
                    mst.erase(mst.find({it}));
                    deg[it]--;
                    mst.insert({it});
                }
            }
        }
        sol[i] = mst.size();
        x = edge[i].first, y = edge[i].second;
        if(deg[x] > 0 && deg[y] > 0) {
            mp[{min(x, y), max(x, y)}] = 1;
            mst.erase(mst.find({x}));
            deg[x]--;
            mst.insert({x});
            mst.erase(mst.find({y}));
            deg[y]--;
            mst.insert({y});
        }
    }
    for(i = 1; i <= m; i++) {
        cout << sol[i] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}