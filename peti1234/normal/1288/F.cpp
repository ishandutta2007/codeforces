#include <bits/stdc++.h>

using namespace std;

const int rossz=1000000, jo=-5000000;
const int c=405, sok=1e9;

int kezd, veg, tav[c], fel[c];
vector<int> sz[c], s[c], ert[c], pos[c];
void add(int a, int b, int kap, int suly) {
    pos[a].push_back(sz[b].size()), pos[b].push_back(sz[a].size());
    sz[a].push_back(b), s[a].push_back(kap), ert[a].push_back(suly);
    sz[b].push_back(a), s[b].push_back(0), ert[b].push_back(-suly);
}
void spfa() {
    for (int i=0; i<=veg; i++) {
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
int kell;
int flow() {
    int ans=0, db=0;
    while (true) {
        spfa();
        if (tav[veg]>=0) {
            break;
        }
        if (abs(tav[veg])<rossz) {
            ans+=tav[veg];
        }
        else if (tav[veg]>jo) {
            kell--;
            ans+=tav[veg]-jo;
        }
        else {
            kell-=2;
            ans+=tav[veg]-2*jo;
        }
        db++;
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

int bal, jobb, m, r, b;
int v1[c], v2[c], res[c];
bool kesz[c];
string bs, js;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> bal >> jobb >> m >> r >> b;
    kezd=0, veg=bal+jobb+1;
    cin >> bs >> js;
    for (int i=0; i<bal; i++) {
        char k=bs[i];
        if (k=='U') {
            add(kezd, i+1, c, 0);
            add(i+1, veg, c, 0);
        }
        if (k=='R') {
            add(kezd, i+1, 1, jo);
            add(kezd, i+1, c, 0);
            kell++;
        }
        if (k=='B') {
            add(i+1, veg, 1, jo);
            add(i+1, veg, c, 0);
            kell++;
        }
    }
    for (int i=0; i<jobb; i++) {
        char k=js[i];
        if (k=='U') {
            add(kezd, bal+i+1, c, 0);
            add(bal+i+1, veg, c, 0);
        }
        if (k=='B') {
            add(kezd, bal+i+1, 1, jo);
            add(kezd, bal+i+1, c, 0);
            kell++;
        }
        if (k=='R') {
            add(bal+i+1, veg, 1, jo);
            add(bal+i+1, veg, c, 0);
            kell++;
        }
    }
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        y+=bal;
        add(x, y, 1, r), add(y, x, 1, b);
        v1[i]=x, v2[i]=y;
    }
    int x=flow();
    if (kell) {
        cout << -1 << "\n";
        return 0;
    }
    cout << x << "\n";
    for (int i=1; i<=bal+jobb; i++) {
        for (int j=0; j<sz[i].size(); j++) {
            int x=sz[i][j], p=s[i][j], suly=ert[i][j];
            if (x!=kezd && x!=veg && p==0 && suly>0) {
                for (int j=1; j<=m; j++) {
                    if (!kesz[j]) {
                        if (i<x && i==v1[j] && x==v2[j]) {
                            kesz[j]=1;
                            res[j]=1;
                            break;
                        }
                        if (i>x && x==v1[j] && i==v2[j]) {
                            kesz[j]=1;
                            res[j]=2;
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i=1; i<=m; i++) {
        if (res[i]==1) {
            cout << "R";
        }
        if (res[i]==2) {
            cout << "B";
        }
        if (res[i]==0) {
            cout << "U";
        }
    }
    cout << "\n";
    return 0;
}