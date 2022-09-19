#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int n, n2, t[c], tt[c], l[c], r[c], felcs[c], felid[c], hol[c], cnt;
vector<pair<int, int> > sz[c];
bool jo[c], v[c];
int kezd, spec, specid;
int m[606][606];
void dfs(int a) {
    hol[a]=kezd;
    v[a]=true;
    if (jo[a]) {
        spec=a;
    }
    for (auto p:sz[a]) {
        int x=p.first, y=p.second;
        if (y!=felid[a]) {
            if (!v[x]) {
                felid[x]=y;
                felcs[x]=a;
                dfs(x);
            } else {
                spec=a;
                specid=y;
            }
        }
    }
}
void add(int cs, int ert) {
    if (jo[cs]) return;
    jo[cs]=1;
    if (t[l[ert]-1]==cs) t[l[ert]]=cs;
    else t[r[ert]]=cs;
}
void spec_add(int spec, int specid, int cel) {
    add(spec, specid);
    while (spec!=cel) {
        specid=felid[spec];
        spec=felcs[spec];
        add(spec, specid);
    }
}

struct blossom {
    int n, m;
    vector<int> mate;
    vector<vector<int>> b;
    vector<int> p, d, bl;
    vector<vector<int>> g;
    blossom(int n) : n(n) {
        m = n + n / 2;
        mate.assign(n, -1);
        b.resize(m);
        p.resize(m);
        d.resize(m);
        bl.resize(m);
        g.assign(m, vector<int>(m, -1));
    }
    void add_edge(int u, int v) {
        g[u][v] = u;
        g[v][u] = v;
    }
    void match(int u, int v) {
        g[u][v] = g[v][u] = -1;
        mate[u] = v;
        mate[v] = u;
    }
    vector<int> trace(int x) {
        vector<int> vx;
        while(true) {
            while(bl[x] != x) x = bl[x];
            if(!vx.empty() && vx.back() == x) break;
            vx.push_back(x);
            x = p[x];
        }
        return vx;
    }
    void contract(int c, int x, int y, vector<int> &vx, vector<int> &vy) {
        b[c].clear();
        int r = vx.back();
        while(!vx.empty() && !vy.empty() && vx.back() == vy.back()) {
            r = vx.back();
            vx.pop_back();
            vy.pop_back();
        }
        b[c].push_back(r);
        b[c].insert(b[c].end(), vx.rbegin(), vx.rend());
        b[c].insert(b[c].end(), vy.begin(), vy.end());
        for(int i = 0; i <= c; i++) {
            g[c][i] = g[i][c] = -1;
        }
        for(int z : b[c]) {
            bl[z] = c;
            for(int i = 0; i < c; i++) {
                if(g[z][i] != -1) {
                    g[c][i] = z;
                    g[i][c] = g[i][z];
                }
            }
        }
    }
    vector<int> lift(vector<int> &vx) {
        vector<int> A;
        while(vx.size() >= 2) {
            int z = vx.back(); vx.pop_back();
            if(z < n) {
                A.push_back(z);
                continue;
            }
            int w = vx.back();
            int i = (A.size() % 2 == 0 ? find(b[z].begin(), b[z].end(), g[z][w]) - b[z].begin() : 0);
            int j = (A.size() % 2 == 1 ? find(b[z].begin(), b[z].end(), g[z][A.back()]) - b[z].begin() : 0);
            int k = b[z].size();
            int dif = (A.size() % 2 == 0 ? i % 2 == 1 : j % 2 == 0) ? 1 : k - 1;
            while(i != j) {
                vx.push_back(b[z][i]);
                i = (i + dif) % k;
            }
            vx.push_back(b[z][i]);
        }
        return A;
    }
    int solve() {
        for(int ans = 0; ; ans++) {
            fill(d.begin(), d.end(), 0);
            queue<int> Q;
            for(int i = 0; i < m; i++) bl[i] = i;
            for(int i = 0; i < n; i++) {
                if(mate[i] == -1) {
                    Q.push(i);
                    p[i] = i;
                    d[i] = 1;
                }
            }
            int c = n;
            bool aug = false;
            while(!Q.empty() && !aug) {
                int x = Q.front(); Q.pop();
                if(bl[x] != x) continue;
                for(int y = 0; y < c; y++) {
                    if(bl[y] == y && g[x][y] != -1) {
                        if(d[y] == 0) {
                            p[y] = x;
                            d[y] = 2;
                            p[mate[y]] = y;
                            d[mate[y]] = 1;
                            Q.push(mate[y]);
                        }else if(d[y] == 1) {
                            vector<int> vx = trace(x);
                            vector<int> vy = trace(y);
                            if(vx.back() == vy.back()) {
                                contract(c, x, y, vx, vy);
                                Q.push(c);
                                p[c] = p[b[c][0]];
                                d[c] = 1;
                                c++;
                            }else {
                                aug = true;
                                vx.insert(vx.begin(), y);
                                vy.insert(vy.begin(), x);
                                vector<int> A = lift(vx);
                                vector<int> B = lift(vy);
                                A.insert(A.end(), B.rbegin(), B.rend());
                                for(int i = 0; i < (int) A.size(); i += 2) {
                                    match(A[i], A[i + 1]);
                                    if(i + 2 < (int) A.size()) add_edge(A[i + 1], A[i + 2]);
                                }
                            }
                            break;
                        }
                    }
                }
            }
            if(!aug) return ans;
        }
    }
};





int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        tt[i]=t[i];
        n2=max(n2, t[i]);
    }
    n2+=3;
    for (int i=2; i<=n; i++) {
        if (t[i]==t[i-1] && t[i]) {
            jo[t[i]]=1;
        }
    }
    int pos=0;
    for (int i=1; i<=n; i++) {
        if (t[i]) {
            if ((i-pos)%2==0) {
                cnt++;
                l[cnt]=pos+1, r[cnt]=i-1;
                int a=(pos==0 ? t[i] : t[pos]), b=t[i];
                sz[a].push_back({b, cnt}), sz[b].push_back({a, cnt});
            }
            pos=i;
        }
    }
    if (pos==0) {
        for (int i=1; i<=n; i++) {
            cout << (i+1)/2 << " ";
        }
        cout << "\n";
        return 0;
    }
    if ((n-pos)%2) {
        cnt++;
        l[cnt]=pos+1, r[cnt]=n;
        int a=t[pos], b=t[pos];
        sz[a].push_back({b, cnt}), sz[b].push_back({a, cnt});
    }
    for (int i=1; i<=n2; i++) {
        if (!v[i]) {
            kezd=i;
            dfs(i);
        }
        if (spec) {
            spec_add(spec, specid, i);
        }

        spec=0, specid=0;
    }

    blossom B(n2);
    pos=0;
    for (int i=1; i<=n; i++) {
        if (t[i]) {
            if (pos!=0 && !jo[t[i]] && !jo[t[pos]] && (i-pos)%2 && i-pos>1) {
                cnt++;
                l[cnt]=pos+1, r[cnt]=i-1;
                int a=hol[t[i]], b=hol[t[pos]];
                if (a>b) swap(a, b);
                if (a<b) {
                    if (!m[a][b]) {
                        m[a][b]=cnt;
                        B.add_edge(a, b);
                    }
                }
            }
            pos=i;
        }
    }
    B.solve();

    for (int i=1; i<n2; i++) {
        if (i<B.mate[i]) {
            int a=i, b=B.mate[i], id=m[a][b];
            int s1=t[l[id]-1], s2=t[r[id]+1];
            int aa=(hol[s1]==a ? s1 : s2), bb=(hol[s1]==b ? s1 : s2);
            spec_add(aa, id, a);
            spec_add(bb, id, b);

        }
    }
    for (int i=1; i<=n2; i++) {
        if (felid[i]) {
            add(i, felid[i]);
        }
    }
    int u=1;
    for (int i=1; i<=n; i++) {
        if (!t[i]) {
            if (i>1 && !jo[t[i-1]]) {
                t[i]=t[i-1];
                jo[t[i]]=1;
            } else {
                while (jo[u]) {
                    u++;
                }
                t[i]=u;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << t[i] << " ";
    }
    cout << "\n";
    return 0;
}