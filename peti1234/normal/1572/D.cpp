#include <bits/stdc++.h>

using namespace std;

const int maxval=2e6;
/*
Min_Cost_Max_Flow
c es sok erteke szabadon valaszthato
10^18-ig kiszamolja (utana nem fer bele a long long)
akkor mukodik, ha nincs negativ sulyu el
ha K a maximalis folyam, akkor O(k*(n+m)*log(n+m))
kezd a legkisebb es veg a legnagyobb csucs
nehany helyen kell atallitani, ugy hogy masra is mukodjon
*/
const int c=400005;
const long long sok=1e15;
int kezd, veg, fel[c];
long long dist[c], pot[c];
vector<int> sz[c], s[c], pos[c];
vector<long long> ert[c];
void add(int a, int b, int kap, long long suly) {
    //cout << "el " << a << " " << b << " " << kap << " " << suly << "\n";
    pos[a].push_back(sz[b].size()), pos[b].push_back(sz[a].size());
    sz[a].push_back(b), s[a].push_back(kap), ert[a].push_back(suly);
    sz[b].push_back(a), s[b].push_back(0), ert[b].push_back(-suly);
}
void dijkstra() {
    for (int i=kezd; i<=veg; i++) {
        dist[i]=sok, fel[i]=-1;
    }
    dist[kezd]=0;
    priority_queue<pair<long long, int> > q;
    q.push({0, kezd});
    while (q.size()>0) {
        int id=q.top().second;
        long long tav=-q.top().first;
        q.pop();
        if (dist[id]==tav) {
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i];
                long long ujtav=tav+ert[id][i]+pot[id]-pot[x];
                if (s[id][i] && ujtav<dist[x]) {
                    dist[x]=ujtav;
                    q.push({-ujtav, x});
                    fel[x]=pos[id][i];
                }
            }
        }
    }
    for (int i=kezd; i<=veg; i++) {
        pot[i]+=dist[i];
    }
}
long long flow(int cnt) {
    long long ans=0;
    for (int i=0; i<cnt; i++) {
        dijkstra();
        if (dist[veg]==sok) {
            break;
        }
        ans+=maxval-pot[veg];
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
// folyam algoritmus vege





















int n, n2, k, cnt, db, t[1050000];
vector<pair<int, pair<int, int> > > el;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    n2=(1<<n);
    for (int i=0; i<n2; i++) {
        cin >> t[i];
    }
    for (int i=0; i<n2; i++) {
        if (__builtin_popcount(i)%2) {
            for (int j=0; j<n; j++) {
                int s=(i^(1<<j));
                el.push_back({t[i]+t[s], {i, s}});
            }
        }
    }
    sort(el.rbegin(), el.rend());
    db=min((int)el.size(), 2*n*k);
    for (int i=0; i<db; i++) {
        int a=el[i].second.first, b=el[i].second.second, si=el[i].first;
        if (m.find(a)==m.end()) {
            m[a]=++cnt;
        }
        if (m.find(b)==m.end()) {
            m[b]=++cnt;
        }
        add(m[a], m[b], 1, maxval-si);
    }
    kezd=0, veg=++cnt;
    for (auto x:m) {
        int db=__builtin_popcount(x.first), id=x.second;
        if (db%2) {
            add(kezd, id, 1, 0);
        } else {
            add(id, veg, 1, 0);
        }
    }
    cout << flow(k) << "\n";
    return 0;
}