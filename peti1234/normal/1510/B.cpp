#include <bits/stdc++.h>

using namespace std;

const int c=2065, sok=1e9, mar=100001;
int kezd, veg, tav[c], fel[c];
vector<int> sz[c], s[c], ert[c], pos[c];
bool volt[c];
int n, d, po, inv[c], sor[c];
bool kell[c], spec[c];
void add(int a, int b, int kap, int suly) {
    pos[a].push_back(sz[b].size()), pos[b].push_back(sz[a].size());
    sz[a].push_back(b), s[a].push_back(kap), ert[a].push_back(suly);
    sz[b].push_back(a), s[b].push_back(0), ert[b].push_back(-10*suly);
}

void spec_dijkstra() {
    for (int i=kezd; i<=veg; i++) {
        tav[i]=sok, fel[i]=0;
        volt[i]=0;
    }
    tav[kezd]=0;
    priority_queue<pair<int, int> > q;
    q.push({0, kezd});
    while(q.size()) {
        int kell=-q.top().first, id=q.top().second;
        volt[id]=1;

        q.pop();
        if (tav[id]==kell) {
            for (int i=0; i<sz[id].size(); i++) {
                int uj=sz[id][i], ss=s[id][i], pl=ert[id][i], visz=pos[id][i];
                if (ss) {
                    int ujtav=kell+pl;
                    if (ujtav<tav[uj]) {
                        tav[uj]=ujtav;
                        fel[uj]=visz;
                        q.push({-ujtav, uj});
                    }
                }
            }
        }
    }
}
int utdb, toroldb;
void flow() {

    while (true) {
        spec_dijkstra();
        int x=veg;
        if (!volt[veg]) {
            return;
        }
        //cout << "ut ";
        utdb++;
        int valt=sz[x][fel[x]];
        kell[valt]=0, spec[valt]=1;
        while(x!=kezd) {
            int ki=fel[x];
            int kov=sz[x][ki], kovh=pos[x][ki];

            if (ert[x][ki]>0 && kell[kov]) {
                toroldb++;
                kell[kov]=0;
                for (int cs=0; cs<sz[kov].size(); cs++) {
                    if (sz[kov][cs]==veg) {
                        s[kov][cs]=0;
                    }
                }
            }
            s[x][ki]++, s[kov][kovh]--;
            x=kov;
        }
    }
    return;
}
 vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> d >> n;

    po=(1<<d);
    kezd=0, veg=2*po;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        int val=0;
        for (int j=0; j<d; j++) {
            if (s[j]=='1') {
                val+=(1<<j);
            }
        }
        kell[val]=1;
    }
    for (int i=0; i<po; i++) {
        sor[i]=2*i, sor[i+po]=2*i+1;
        add(i, i+po, mar, 0);
        if (kell[i]) {
            add(i, veg, 1, 0);
            add(i, i+po, 1, -__builtin_popcount(i)-1);
        }
        for (int j=0; j<d; j++) {
            if (!(i & (1<<j))) {
                add(i+po, i+(1<<j), mar, 0);
            }
        }
    }
    sor[veg]=c;
    flow();
    while (true) {
        bool nincs=0;
        int most=kezd;
        while (most!=veg) {
            bool jo=0;
            for (int i=0; i<sz[most].size(); i++) {
                int kov=sz[most][i];
                if (s[most][i]%10000!=1 && sor[kov]>sor[most]) {
                    s[most][i]++;
                    jo=1;

                    if (kov==veg) {
                        if (!spec[most]) {
                            continue;
                        }
                        ans.push_back('R');
                    } else {
                        int a=most%po, b=kov%po;
                        if (a!=b) {
                            ans.push_back('0'+__builtin_ctz(b-a));
                        }
                    }
                    jo=1;
                    most=kov;
                    break;
                }
            }
            if (!jo) {
                nincs=1;
                break;
            }
        }
        if (nincs) {
            break;
        }
    }
    ans.pop_back();
    cout << ans.size() << "\n";
    for (char i:ans) {
        cout << i << " ";
    }
    return 0;
}