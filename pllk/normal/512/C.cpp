#include <iostream>
#include <vector>

using namespace std;

#define _ft int
#define _fs 101010
struct flow {
    vector<int> v[_fs];
    vector<_ft> p[_fs];
    vector<int> t[_fs];
    
    void add(int a, int b, _ft x) {
        t[a].push_back(v[b].size());
        t[b].push_back(v[a].size());
        v[a].push_back(b);
        v[b].push_back(a);
        p[a].push_back(x);
        p[b].push_back(0);
    }
    
    int calc(int a, int b) {
        _ft f = 0;
        while (true) {
            vector<int> ps, pk, pe;
            vector<int> pp(_fs);
            ps.push_back(a);
            pk.push_back(-1);
            pe.push_back(-1);
            bool ok = false;
            for (int i = 0; i < ps.size(); i++) {
                int s = ps[i];
                for (int j = 0; j < v[s].size(); j++) {
                    int u = v[s][j];
                    if (pp[u]) continue;
                    if (p[s][j] <= 0) continue;
                    pp[u] = 1;
                    ps.push_back(u);
                    pk.push_back(j);
                    pe.push_back(i);
                    if (u == b) {ok = true; goto end;}
                }
            }
            end:
            if (!ok) break;
            int k = ps.size()-1;
            int x = 0;
            while (k != 0) {
                int u = p[ps[pe[k]]][pk[k]];
                if (x == 0 || u < x) x = u;
                k = pe[k];
            }
            k = ps.size()-1;
            while (k != 0) {
                p[ps[pe[k]]][pk[k]] -= x;
                p[ps[k]][t[ps[pe[k]]][pk[k]]] += x;
                k = pe[k];
            }
            f += x;
        }
        return f;
    }
};

int n;
flow x;
vector<int> a, b;
vector<int> aa, bb;

bool ok(int z1, int z2) {
    int z = z1+z2;
    for (int i = 2; i*i <= z; i++) {
        if (z%i == 0) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int z;
        cin >> z;
        if (z%2 == 0) a.push_back(z);
        else b.push_back(z);
        if (z%2 == 0) aa.push_back(i+1);
        else bb.push_back(i+1);
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (ok(a[i],b[j])) x.add(1+i,1000+j, 1);
        }
    }
    for (int i = 0; i < a.size(); i++) x.add(0, 1+i, 2);
    for (int i = 0; i < b.size(); i++) x.add(1000+i, 2000, 2);
    
    int t = x.calc(0,2000);
    if (t != n) {
        cout << "Impossible\n";
        return 0;
    }
    
    vector<int> c[2000];
    vector<int> ok(2000);
    
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < x.v[i+1].size(); j++) {
            if (x.p[i+1][j] == 0) {
                c[i+1].push_back(x.v[i+1][j]);
                c[x.v[i+1][j]].push_back(i+1);
            }
        }
    }
    
    vector<vector<int>> tt;
    for (int i = 0; i < a.size(); i++) {
        if (ok[i+1]) continue;
        ok[i+1] = 1;
        vector<int> uu;
        uu.push_back(i+1);
        int q = c[i+1][0];
        int w = i+1;
        while (true) {
            uu.push_back(q);
            if (c[q][0] == w) {w = q; q = c[q][1];}
            else {w = q; q = c[q][0];}
            if (q == i+1) break;
            ok[q] = 1;
        }
        tt.push_back(uu);
    }
    cout << tt.size() << "\n";
    for (int i = 0; i < tt.size(); i++) {
        auto uu = tt[i];
        cout << uu.size() << " ";
        for (auto u : uu) {
            if (u < 1000) cout << aa[u-1] << " ";
            else cout << bb[u-1000] << " ";
        }
        cout << "\n";
    }
}