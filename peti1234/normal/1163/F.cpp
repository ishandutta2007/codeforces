#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, w, cs1[c], cs2[c], hossz[c];
int fel[c], felid[c], kezd[c], si;
vector<int> sor, fout;
vector<long long> rovid[c];
vector<pair<int, int> > sz[c];
vector<int> sz2[c];
multiset<long long> opt;
long long diste[c], distn[c], potut[c], sok=1e16;
bool v[c], v2[c];
priority_queue<pair<long long, int> > q;
void add(long long tav, int id) {
    q.push({-tav, id});
}
void foutresz() {
    int pos=n;
    while (pos) {
        fout.push_back(pos);
        pos=fel[pos];
    }
    si=fout.size();
    reverse(fout.begin(), fout.end());
    for (int i=0; i<si; i++) {
        kezd[fout[i]]=i+1;
        potut[i+1]=sok;
    }
    for (int x:sor) {
        if (!kezd[x]) {
            kezd[x]=kezd[fel[x]];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> w;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cs1[i]=a, cs2[i]=b, hossz[i]=c;
        sz[a].push_back({b, c}), sz[b].push_back({a, c});
        sz2[a].push_back(i), sz2[b].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        diste[i]=sok, distn[i]=sok;
    }
    add(0, n);
    while (q.size()>0) {
        long long tav=-q.top().first, id=q.top().second;
        q.pop();
        if (!v2[id]) {
            v2[id]=1;
            distn[id]=tav;
            for (auto el:sz[id]) {
                long long uj=tav+el.second, x=el.first;
                if (!v[x]) {
                    add(uj, x);
                }
            }
        }
    }
    diste[1]=0;
    add(0, 1);
    while (q.size()>0) {
        long long tav=-q.top().first, id=q.top().second;
        q.pop();
        if (!v[id]) {
            sor.push_back(id);
            v[id]=1;
            for (int i=0; i<sz[id].size(); i++) {
                auto el=sz[id][i];
                int elid=sz2[id][i];
                long long uj=tav+el.second, x=el.first;
                if (uj<diste[x]) {
                    diste[x]=uj;
                    add(uj, x);
                    fel[x]=id;
                    felid[x]=elid;
                }
            }
        }
    }
    foutresz();
    for (int el=1; el<=m; el++) {
        int a=cs1[el], b=cs2[el];
        if (felid[a]==el || felid[b]==el) {
            continue;
        }
        int be=kezd[a], ki=kezd[b];
        if (be>ki) {
            swap(ki, be);
            swap(a, b);
        }
        long long tav=min(diste[a]+distn[b], diste[b]+distn[a])+hossz[el];
        if (be<ki) {
            rovid[be].push_back(tav), rovid[ki].push_back(-tav);
        }
    }
    opt.insert(sok);
    for (int i=1; i<si; i++) {
        for (long long x:rovid[i]) {
            if (x>0) {
                opt.insert(x);
            } else {
                opt.erase(opt.find(-x));
            }
        }
        potut[i]=*opt.begin();
    }
    while (w--) {
        int id;
        long long ert;
        cin >> id >> ert;
        int bal=cs1[id], jobb=cs2[id], rh=hossz[id];
        if (ert<=rh) {
            cout << min(diste[n], min(diste[bal]+distn[jobb], distn[bal]+diste[jobb])+ert) << "\n";
        } else {
            if (kezd[bal]==kezd[jobb] || (felid[bal]!=id && felid[jobb]!=id)) {
                cout << diste[n] << "\n";
            } else {
                int s=(fel[bal]==jobb ? kezd[jobb] : kezd[bal]);
                cout << min(diste[n]+ert-rh, potut[s]) << "\n";
            }
        }
    }
    return 0;
}