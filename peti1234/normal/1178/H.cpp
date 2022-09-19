#include <bits/stdc++.h>

using namespace std;

/*
Min_Cost_Max_Flow
c es sok erteke szabadon valaszthato
10^18-ig kiszamolja (utana nem fer bele a long long)
akkor mukodik, ha nincs negativ sulyu el
ha K a maximalis folyam, akkor O(k*(n+m)*log(n+m))
kezd a legkisebb es veg a legnagyobb csucs
nehany helyen kell atallitani, ugy hogy masra is mukodjon
*/
const int c=18005, sok=1e9;

int folyam, koltseg;

int kezd, veg, fel[c];
int dist[c], pot[c];
vector<int> sz[c], s[c], pos[c], ert[c];
void add(int a, int b, int kap, int suly) {
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
    priority_queue<pair<int, int> > q;
    q.push({0, kezd});
    while (q.size()>0) {
        int id=q.top().second;
        int tav=-q.top().first;
        q.pop();
        if (dist[id]==tav) {
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i];
                int ujtav=tav+ert[id][i]+pot[id]-pot[x];
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
void min_cost_max_flow() {
    folyam=0, koltseg=0;
    while (true) {
        dijkstra();
        if (dist[veg]==sok) {
            break;
        }
        folyam++;
        koltseg+=pot[veg];
        int x=veg;
        while(fel[x]!=-1) {
            int ki=sz[x][fel[x]];
            int inv=pos[x][fel[x]];
            s[x][fel[x]]++, s[ki][inv]--;
            x=ki;
        }
    }
    return;
}


int f, n;
long long aa[c], bb[c], lo, hi, mid;

bool folyam_nelkul(long long mid) {
    vector<pair<pair<long long, long long>, int> > sor;
    vector<long long> cel, val;
    long long maxi=0;
    for (int i=1; i<=n; i++) {
        sor.push_back({{bb[i], -(bb[i]+mid*aa[i])}, i});
    }
    sort(sor.begin(), sor.end());

    for (auto x:sor) {
        int id=x.second;
        long long p=-x.first.second;
        maxi=max(maxi, p);
        if (id<=f) {
            val.push_back(maxi);
        } else {
            cel.push_back(p);
        }
    }

    sor.clear();

    bool jo=1;
    sort(cel.begin(), cel.end()), sort(val.begin(), val.end());
    for (int i=0; i<f; i++) {
        if (cel[i]>val[i]) {
            jo=0;
        }
    }
    return jo;
}

bool calc(long long mid) {
    vector<pair<long long, int> > sor;
    for (int i=1; i<=f; i++) {
        add(kezd, i, 1, 0);
    }
    for (int i=1; i<=n; i++) {
        add(i, i+n, c, 0);
    }
    for (int i=f+1; i<=n; i++) {
        add(i+n, veg, 1, 0);
    }

    for (int i=1; i<=n; i++) {
        sor.push_back({bb[i], i});
    }
    sort(sor.rbegin(), sor.rend());
    int val=2*n;
    for (int i=0; i<n; i++) {
        val++;
        int id=sor[i].second;
        add(id, val, c, 1);
        add(val, id, c, 0);
        if (val<3*n) {
            add(val, val+1, c, 0);
            if (sor[i].first==sor[i+1].first) {
                add(val+1, val, c, 0);
            }
        }
    }
    sor.clear();
    for (int i=1; i<=n; i++) {
        sor.push_back({aa[i]*mid+bb[i], i});
    }
    sort(sor.rbegin(), sor.rend());
    assert(val==3*n);
    for (int i=0; i<n; i++) {
        val++;
        int id=sor[i].second+n;
        add(id, val, c, 1);
        add(val, id, c, 0);
        if (val<4*n) {
            add(val, val+1, c, 0);
            if (sor[i].first==sor[i+1].first) {
                add(val+1, val, c, 0);
            }
        }
    }
    sor.clear();
    min_cost_max_flow();
    for (int i=kezd; i<=veg; i++) {
        fel[i]=0, dist[i]=0, pot[i]=0;
        sz[i].clear(), s[i].clear(), pos[i].clear(), ert[i].clear();
    }

    return (folyam==f);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> f;
    n=2*f;
    kezd=0, veg=4*n+1;
    for (int i=1; i<=n; i++) {
        cin >> aa[i] >> bb[i];
    }
    lo=-1, hi=1e9;
    if (!folyam_nelkul(hi)) {
        cout << -1 << "\n";
        return 0;
    }
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (folyam_nelkul(mid)) hi=mid;
        else lo=mid;
    }
    calc(hi);
    cout << hi << " " << koltseg << "\n";
    return 0;
}