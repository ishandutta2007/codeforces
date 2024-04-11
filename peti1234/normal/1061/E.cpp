#include <bits/stdc++.h>

using namespace std;

const int c=1002, sok=1e9;
int kezd, veg, tav[c], fel[c];
vector<int> sz[c], s[c], ert[c], pos[c];
bool volt[c];
int eldb;
void add(int a, int b, int kap, int suly) {
    if (kap<0) {
        eldb=sok;
    }
    pos[a].push_back(sz[b].size()), pos[b].push_back(sz[a].size());
    sz[a].push_back(b), s[a].push_back(kap), ert[a].push_back(suly);
    sz[b].push_back(a), s[b].push_back(0), ert[b].push_back(-suly);
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
int flow() {

    int ans=0;
    for (int i=1; i<=eldb; i++) {
        spec_dijkstra();
        if (!volt[veg]) {
            return -1;
        }
        ans+=tav[veg];
        int x=veg;
        while(x) {
            int ki=fel[x];
            int kov=sz[x][ki], kovh=pos[x][ki];
            s[x][ki]++, s[kov][kovh]--;
            x=kov;
        }
    }
    return -ans;
}

const int f=502;
int n, bal, jobb, baldb, jobbdb, balkr[f], jobbkr[f], balcs[f], jobbcs[f], val[f], balrf[c], jobbrf[c], cnt;
vector<int> balel[f], jobbel[f], balv[f], jobbv[f];
bool v1[f], v2[f];
void baldfs(int a) {
    v1[a]=true;
    for (int x:balel[a]) {
        if (!v1[x]) {
            baldfs(x);
            balrf[a]+=balrf[x];
            for (int uj:balv[x]) {
                balv[a].push_back(uj);
            }
        }
    }
    balv[a].push_back(a);
    if (balkr[a]) {
        cnt++;
        add(kezd, cnt, balkr[a]-balrf[a], 0);
        for (int x:balv[a]) {
            balcs[x]=cnt;
        }
        balrf[a]=balkr[a];
        balv[a].clear();
    }
}
void jobbdfs(int a) {
    v2[a]=true;
    for (int x:jobbel[a]) {
        if (!v2[x]) {
            jobbdfs(x);
            jobbrf[a]+=jobbrf[x];
            for (int uj:jobbv[x]) {
                jobbv[a].push_back(uj);
            }
        }
    }
    jobbv[a].push_back(a);
    if (jobbkr[a]) {
        cnt++;
        add (cnt, veg, jobbkr[a]-jobbrf[a], 0);
        for (int x:jobbv[a]) {
            jobbcs[x]=cnt;
        }
        jobbrf[a]=jobbkr[a];
        jobbv[a].clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> bal >> jobb;
    for (int i=1; i<=n; i++) {
        cin >> val[i];
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        balel[a].push_back(b), balel[b].push_back(a);
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        jobbel[a].push_back(b), jobbel[b].push_back(a);
    }
    cin >> baldb;
    for (int i=1; i<=baldb; i++) {
        int a, b;
        cin >> a >> b;
        balkr[a]=b;
    }
    cin >> jobbdb;
    for (int i=1; i<=jobbdb; i++) {
        int a, b;
        cin >> a >> b;
        jobbkr[a]=b;
    }
    kezd=0, veg=baldb+jobbdb+1;
    eldb=max(balkr[bal], jobbkr[jobb]);
    baldfs(bal);
    jobbdfs(jobb);
    for (int i=1; i<=n; i++) {
        int x=balcs[i], y=jobbcs[i];
        add(x, y, 1, -val[i]);
    }
    cout << flow() << "\n";

    return 0;
}