#include<bits/stdc++.h>

using namespace std;
const int c=2000005;
int w, n, m, fel[c], szint[c], kezd, veg;
int ki[c], eldb, si[c], r[c], ki2[c];
vector<int> sz[c];
vector<pair<int, int> > spec;
bool v[c], kor[c], kor2, pkor, kesz;
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            fel[x]=a;
            szint[x]=szint[a]+1;
            dfs(x);
        } else if (szint[a]>szint[x] && szint[a]%2==szint[x]%2 && !kor2) {
            kezd=a, veg=x;
            kor2=1;
            int sa=a;
            while (sa!=x) {
                kor[sa]=1;
                spec.push_back({sa, fel[sa]});
                sa=fel[sa];
            }
            spec.push_back({x, a});
            kor[x]=1;
        }
    }
}
int holvan(int a) {
    if (ki[a]) return holvan(ki[a]);
    return a;
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        eldb++;
        if (si[a]<si[b]) {
            ki[a]=b, si[b]+=si[a];
            r[eldb]=a;
        } else {
            ki[b]=a, si[a]+=si[b];
            r[eldb]=b;
        }
    }
}
bool unio2(int a, int b) {
    unio(a, b+n), unio(a+n, b);
    return (holvan(a)==holvan(a+n));
}
void torol(int ert) {
    while(eldb>ert) {
        int v=r[eldb];
        si[ki[v]]-=si[v], ki[v]=0;
        eldb--;
    }
}
bool jo(int a, int b) {
    if (szint[a]<szint[b]) swap(a, b);
    if (kor[a] && kor[b] && fel[a]==b || a==kezd && b==veg) return false;
    return true;
}
int sholvan(int a) {
    return (ki2[a] ? ki2[a]=sholvan(ki2[a]) : a);
}
void sunio(int a, int b) {
    a=sholvan(a), b=sholvan(b);
    if (a!=b) {
        ki2[a]=b;
    }
}
void solve(int a, int b) {
    kesz=1;
    cout << "YES\n";
    for (int aa=1; aa<=m; aa++) {
        for (auto bb:sz[aa]) {
            if (aa>bb) continue;
            if (a==aa && b==bb || a==bb && b==aa) continue;
            sunio(aa, bb+n);
            sunio(aa+n, bb);
        }
    }
    for (int i=1; i<=n; i++) {
        cout << (sholvan(i)==sholvan(a));
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=2*n; i++) {
            si[i]=1;
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        if (!kor2) {
            solve(1, 0);
        } else {
            for (int i=1; i<=n; i++) {
                for (auto x:sz[i]) {
                    if (i<x && jo(i, x)) {
                        if (unio2(i, x)) {
                            pkor=1;
                        }
                    }
                }
            }
            while (!pkor) {
                int st=eldb, si=spec.size();
                for (int i=0; i<si; i++) {
                    int a=spec[i].first, b=spec[i].second;
                    if (i==si-1) {
                        solve(a, b);
                        pkor=1;
                        break;
                    }
                    if (unio2(a, b)) {
                        torol(st);
                        while (si>i+1) {
                            int x=spec[si-1].first, y=spec[si-1].second;
                            if (unio2(x, y)) {
                                pkor=1;
                            }
                            spec.pop_back();
                            si--;
                        }
                    }
                }
            }
            if (!kesz) {
                cout << "NO\n";
            }
        }
        for (int i=0; i<=max(m, 2*n); i++) {
            fel[i]=0, szint[i]=0, ki[i]=0, si[i]=0, r[i]=0, ki2[i]=0;
            sz[i].clear();
            v[i]=0, kor[i]=0;
        }
        kesz=0, kor2=0, pkor=0, eldb=0;
        kezd=0, veg=0;
        spec.clear();
    }
	return 0;
}