#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long n, m, sum, xo, comp, elhiany, ki[c], melyik[c];
bool fahiany, jon[c];
set<int> el[c];
set<int> vis;
vector<pair<long long, pair<int, int> > > mst;
void dfs(int a) {
    //cout << "dfs " << a << "\n";
    vis.erase(a);
    vector<int> tovabb;
    for (int kov:vis) {
        if (!jon[kov] && el[a].find(kov)==el[a].end()) {
            tovabb.push_back(kov);
        }
    }
    for (auto x:tovabb) {
        vis.erase(x);
    }
    for (auto x:tovabb) {
        ki[x]=ki[a];
        dfs(x);
    }
}
int holvan(int a) {
    if (ki[a]==a || ki[a]==0) {
        return a;
    }
    return ki[a]=holvan(ki[a]);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}
int holvan2(int a) {
    if (melyik[a]==a || melyik[a]==0) {
        return a;
    }
    return melyik[a]=holvan2(melyik[a]);
}
void unio2(int a, int b) {
    //cout << "unio2 " << a << " " << b << "\n";
    a=holvan2(a), b=holvan2(b);
    if (a!=b) {
        melyik[a]=b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    elhiany=n*(n-1)/2-m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        xo^=c;
        el[a].insert(b);
        el[b].insert(a);
        mst.push_back({c, {a, b}});
    }
    for (int i=1; i<=n; i++) {
        vis.insert(i);
    }
    for (int i=1; i<=n; i++) {
        if (vis.find(i)!=vis.end()) {
            //cout << "uj " << i << "\n";
            comp++;
            ki[i]=i;
            dfs(i);
        }
    }
    if (elhiany+comp==n) {
        fahiany=1;
    }
    sort(mst.begin(), mst.end());
    if (!fahiany) {
        for (auto p:mst) {
            long long suly=p.first;
            int bal=p.second.first, jobb=p.second.second;
            //cout << bal << " " << jobb << " " << suly << "\n";
            if (holvan(bal)!=holvan(jobb)) {
                unio(bal, jobb);
                sum+=suly;
            }
        }
        cout << sum << "\n";
    } else {
        //cout << "specailis\n";
        for (int i=1; i<=n; i++) {
            melyik[i]=i;
        }
        bool kesz=0;
        for (auto p:mst) {
            long long suly=p.first;
            int bal=p.second.first, jobb=p.second.second;
            int s1=holvan(bal), s2=holvan(jobb);
            int spec1=holvan2(bal), spec2=holvan2(jobb);
            if (!kesz && spec1!=spec2 && s1==s2) {
                kesz=1;
                sum+=min(suly, xo);
                unio(s1, s2);
            }
            else {
                if (s1!=s2)  {
                    sum+=suly;
                    unio(s1, s2);
                    unio2(spec1, spec2);
                }
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
/*
5 9
1 2 1
2 3 1
4 1 2
4 2 3
4 3 3
3 1 7
3 5 16
2 5 232
1 5 2222
*/