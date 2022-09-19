#include <bits/stdc++.h>

using namespace std;

const int c=400002, f=20;

int n, k, sp, w, cl[c], ki[c], tav[c];
queue<int> q;
vector<int> sz[c];

int holvan(int a) {
    if (!ki[a]) {
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

int szint[c], fel[c][f];
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (int i=1; i<f; i++) {
        fel[a][i]=fel[fel[a][i-1]][i-1];
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a;
            dfs(x);
        }
    }
}

int lep(int a, int b) {
    for (int i=0; i<f; i++) {
        if (b&(1<<i)) {
            a=fel[a][i];
        }
    }
    return a;
}
int lca(int a, int b) {
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    a=lep(a, szint[a]-szint[b]);
    for (int i=f-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            a=fel[a][i], b=fel[b][i];
        }
    }
    if (a!=b) {
        a=fel[a][0];
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> sp;
    for (int i=1; i<n; i++) {
        int a, b, c=n+i;
        cin >> a >> b;
        sz[a].push_back(c), sz[c].push_back(b);
        sz[b].push_back(c), sz[c].push_back(a);
    }

    for (int i=1; i<=sp; i++) {
        int x; cin >> x;
        cl[x]=x;
        q.push({x});
    }

    while (q.size()>0) {
        int a=q.front();
        q.pop();
        if (tav[a]<k) {
            for (int x:sz[a]) {
                if (!cl[x]) {
                    cl[x]=cl[a];
                    ki[x]=a;
                    tav[x]=tav[a]+1;
                    q.push(x);
                } else {
                    if (cl[a]!=cl[x]) {
                        unio(cl[a], cl[x]);
                    }
                }
            }
        }
    }

    dfs(1);

    cin >> w;
    for (int i=1; i<=w; i++) {
        int a, b, s, d1, d2, f1, f2; cin >> a >> b;
        s=lca(a, b);
        d1=szint[a]-szint[s], d2=szint[b]-szint[s];
        bool jo=(d1+d2<=2*k);
        if (d1>=k) {
            f1=lep(a, k);
        } else {
            f1=lep(b, d1+d2-k);
        }
        if (d2>=k) {
            f2=lep(b, k);
        } else {
            f2=lep(a, d1+d2-k);
        }
        if (holvan(f1)==holvan(f2)) {
            jo=1;
        }
        cout << (jo? "YES" : "NO") << "\n";
    }
    return 0;
}