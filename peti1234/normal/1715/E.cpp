#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, m, k, regi[c], uj[c], sok=1e12;
vector<pair<int, int> > sz[c];
vector<int> spec;
void csere() {
    for (int i=1; i<=n; i++) {
        assert(regi[i]>=uj[i]);
        regi[i]=uj[i];
        uj[i]=sok;
    }
}
bool fix[c];
priority_queue<pair<long long, int> > q;
void dijkstra() {
    for (int i=1; i<=n; i++) {
        q.push({-regi[i], i});
    }
    while (q.size()>0) {
        int id=q.top().second;
        long long tav=-q.top().first;
        q.pop();

        if (fix[id]) continue;
        fix[id]=1;
        uj[id]=tav;
        //cout << "dijkstra " << id << " " << regi[id] << " " << tav << "\n";
        for (auto p:sz[id]) {
            int x=p.first;
            long long y=tav+p.second;
            if (!fix[x]) {
                q.push({-y, x});
            }
        }
    }

    for (int i=1; i<=n; i++) fix[i]=0;
    csere();
}
long long mp(int a, int b) {
    /* A elobb van, mint B
     -vegtelenben A jobb, +vegtelenben B
     az elso egesz, ahol B a jobb */
     assert(a<b);
     long long dif=regi[b]-regi[a], tav=b-a;
     // elso olyan szam, ahol 2*tav*x+tav^2>=dif
     dif-=tav*tav;
     if (dif>=0) {
        return b+(dif+2*tav-1)/(2*tav);
     } else {
        return b-(-dif/(2*tav));
     }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back({b, c}), sz[b].push_back({a, c});
    }
    for (int i=1; i<=n; i++) {
        regi[i]=sok, uj[i]=sok;
    }
    regi[1]=0;
    dijkstra();

    for (int j=1; j<=k; j++) {
        for (int i=1; i<=n; i++) {
            while (true) {
                bool t=0;
                int si=spec.size();
                if (si>=1 && mp(spec.back(), i)<=1) {
                    t=1;
                    spec.pop_back();
                } else if (si>=2) {
                    int a=spec[si-2], b=spec[si-1];
                    if (mp(a, b)>=mp(b, i)) {
                        t=1;
                        spec.pop_back();
                    }
                }
                if (!t) break;
            }
            if (spec.size()==0 || mp(spec.back(), i)<=n) {
                spec.push_back(i);
            }
        }

        int ut=n+1;
        while (spec.size()>0) {
            long long pos=spec.back();
            spec.pop_back();
            int kov=(spec.size()>0 ? mp(spec.back(), pos) : 1);
            for (int i=kov; i<ut; i++) {
                long long ert=regi[pos]+(pos-i)*(pos-i);
                assert(ert<=regi[i]);
                uj[i]=ert;
            }
            ut=kov;
        }
        csere();



        dijkstra();
    }
    for (int i=1; i<=n; i++) {
        cout << regi[i] << " ";
    }
    cout << "\n";
    return 0;
}
/*
3 1 2
1 3 1
*/