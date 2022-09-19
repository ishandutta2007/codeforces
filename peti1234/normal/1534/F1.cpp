#include <bits/stdc++.h>
 
using namespace std;
const int c=4000005;
int nn, mm, db[c];
vector<vector<int> > t;
 
int n, kie[c], comp, be[c];
vector<int> sz[c], rev[c];
vector<int> sor;
bool v[c], v2[c];
 
 
bool jo(int a, int b) {
    return (0<=a && a<nn && 0<=b && b<mm && t[a][b]);
}
void add(int a, int b) {
    sz[a].push_back(b);
    rev[b].push_back(a);
}
 
 
void dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    sor.push_back(a);
}
void dfs2(int a) {
    v2[a]=true;
    for (int x:rev[a]) {
        if (!v2[x]) {
            kie[x]=kie[a];
            dfs2(x);
        }
    }
}
 
int main()
{
    cin >> nn >> mm;
    t.resize(nn);
    for (int i=0; i<nn; i++) {
        t[i].resize(mm, 0);
    }
    for (int i=0; i<nn; i++) {
        for (int j=0; j<mm; j++) {
            char c;
            cin >> c;
            if (c=='#') {
                n++;
                t[i][j]=n;
            }
        }
    }
    for (int i=0; i<mm; i++) {
        cin >> db[i];
    }
    if (!n) {
        cout << 0 << "\n";
        return 0;
    }
    if (mm==1) {
        cout << 1 << "\n";
        return 0;
    }
    for (int i=0; i<nn; i++) {
        for (int j=0; j<mm; j++) {
            int x=t[i][j];
            if (x) {
                if (jo(i-1, j)) add(x, t[i-1][j]);
                if (jo(i+1, j)) add(x, t[i+1][j]);
                if (jo(i, j-1)) add(x, t[i][j-1]);
                if (jo(i, j+1)) add(x, t[i][j+1]);
            }
        }
    }
    for (int j=0; j<mm-1; j++) {
        int pos=0;
        for (int i=0; i<nn; i++) {
            if (t[i][j]) {
                if (pos) {
                    add(pos, t[i][j]);
                }
                pos=t[i][j];
            } else if (t[i][j+1]) {
                if (pos) {
                    add(pos, t[i][j+1]);
                }
                pos=t[i][j+1];
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
        }
    }
    reverse(sor.begin(), sor.end());
    for (auto x:sor) {
        if (!v2[x]) {
            comp++;
            kie[x]=x;
            dfs2(x);
        }
    }
    for (int i=1; i<=n; i++) {
        for (auto y:sz[i]) {
            int x=kie[y];
            if (kie[i]!=x) {
                if (!be[x]) {
                    comp--;
                    be[x]++;
                }
            }
        }
    }
    cout << comp << "\n";
    return 0;
}