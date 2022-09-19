#include <bits/stdc++.h>

using namespace std;


vector<vector<pair<int, int>>> rmq_mini, rmq_maxi;
vector<int> rmq_log;
void rmq_init(vector<int> sz) {
    int n=sz.size();
    rmq_log.resize(n+1);
    for (int i=2; i<=n; i++) {
        rmq_log[i]=rmq_log[i/2]+1;
    }
    int po=1, db=1;
    while (po<=n) {
        po*=2, db++;
    }
    rmq_mini.resize(db);
    rmq_maxi.resize(db);
    for (int i=0; i<db; i++) {
        rmq_mini[i].resize(n);
        rmq_maxi[i].resize(n);
    }
    for (int i=0; i<n; i++) {
        rmq_mini[0][i]={sz[i], i};
        rmq_maxi[0][i]={sz[i], i};
    }
    for (int j=1; j<db; j++) {
        for (int i=0; i+(1<<j)<=n; i++) {
            int s=i+(1<<(j-1));
            rmq_mini[j][i]=min(rmq_mini[j-1][i], rmq_mini[j-1][s]);
            rmq_maxi[j][i]=max(rmq_maxi[j-1][i], rmq_maxi[j-1][s]);
        }
    }
}
pair<int, int> rmq_ask(int l, int r, int id) {
    if (r<l) return {0, 0};
    int s=rmq_log[r-l+1], s2=r+1-(1<<s);
    if (!id) {
        return min(rmq_mini[s][l], rmq_mini[s][s2]);
    } else {
        return max(rmq_maxi[s][l], rmq_maxi[s][s2]);
    }
}



const int c=200005;
int w, n, m, q, ki[c], si[c];
set<int> comp[c];
int holvan(int a) {
    return (ki[a] ? holvan(ki[a]) : a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> m >> q;
        vector<int> sz(n+1, 0);
        for (int i=1; i<=n; i++) {
            ki[i]=0, si[i]=1;
            comp[i].clear();
            comp[i].insert(i);
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            a=holvan(a), b=holvan(b);
            if (a==b) continue;
            if (si[a]>si[b]) swap(a, b);
            for (auto p:comp[a]) {
                if (comp[b].find(p-1)!=comp[b].end()) sz[p-1]=i;
                if (comp[b].find(p+1)!=comp[b].end()) sz[p]=i;
            }
            for (auto p:comp[a]) {
                comp[b].insert(p);
            }
            si[b]+=si[a], si[a]=0;
            ki[a]=b;
        }
        rmq_init(sz);
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << rmq_ask(l, r-1, 1).first << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
3
2 1 3
1 2
1 1
1 2
2 2
3 2 6
2 1
1 3
1 1
1 2
1 3
2 2
2 3
3 3
3 2 6
2 3
1 2
1 1
1 2
1 3
2 2
2 3
3 3
*/