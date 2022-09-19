#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, db[c], p[c], q[c];
int xx=1, yy=1, dist, szint[c][4], val[c][4], dist2[c][4];
vector<int> sz[c];
bool v[c], v2[c][4], baj[4], spec[c][4];
void dfs(int a) {
    v[a]=true;
    int cs1=a, cs2=a, tav1=0, tav2=0;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            if (q[x]+1>tav2) {
                tav2=q[x]+1;
                cs2=p[x];
                if (tav2>tav1) {
                    swap(tav1, tav2);
                    swap(cs1, cs2);
                }
            }
        }
    }
    if (tav1+tav2>dist) {
        dist=tav1+tav2;
        xx=cs1, yy=cs2;
    }
    p[a]=cs1, q[a]=tav1;
}

void dfs2(int a, int b) {
    v2[a][b]=true;
    int db=sz[a].size(), ll=szint[a][b];
    dist2[a][b]=ll;
    if (val[ll][b] && val[ll][b]!=db) {
        baj[b]=1;
    }
    val[ll][b]=db;
    for (auto x:sz[a]) {
        if (!v2[x][b]) {
            szint[x][b]=ll+1;
            if (sz[x].size()<=2 && spec[a][b]) {
                spec[x][b]=1;
            }
            dfs2(x, b);
        }
    }
}

void ch(int a, int b) {
    spec[a][b]=1;
    dfs2(a, b);
    if (!baj[b]) {
        cout << a << "\n";
        exit(0);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    //cout << "ertekek " << dist << " " << xx << " " << yy << "\n";
    //return 0;
    ch(xx, 0), ch(yy, 1);
    for (int i=1; i<=n; i++) {
        if (dist2[i][0]+dist2[i][1]==dist && dist2[i][0]==dist2[i][1]) {
            ch(i, 2);
            int opt=0;
            for (int i=1; i<=n; i++) {
                if (sz[i].size()==1 && spec[i][2] && (opt==0 || szint[i][2]<szint[opt][2])) {
                    opt=i;
                }
            }
            //cout << "fontos " << i << " " << opt << "\n";
            if (opt) {
                ch(opt, 3);
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
/*
16
1 2 2 3 3 4 3 5
1 6 6 7 7 8 7 9
1 10 10 11 11 12
1 13 13 14 14 15 14 16
*/