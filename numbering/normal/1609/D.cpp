#include <bits/stdc++.h>
#define int long long
using namespace std;
int X[1005];
int Y[1005];
int cnt = 0;
set<int> S;
struct UnionFind {
    vector<int> root;
    UnionFind(int N) {
        root.resize(N);
        fill(root.begin(),root.end(),-1);
    }
    int Find(int x) {
        if(root[x] < 0) return x;
        int r = Find(root[x]);
        root[x] = r;
        return r;
    }
    void Merge(int x, int y) {
        x = Find(x), y = Find(y);
        if(x == y) {
            cnt++;
            return;
        }
        if(root[x] > root[y]) swap(x, y);
        root[x] += root[y];
        root[y] = x;
    }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, d;
    cin >> N >> d;
    int i, j;
    for(i=0;i<d;i++) {
        cin >>X[i] >> Y[i];
        X[i]--;
        Y[i]--;
    }
    UnionFind UF(N);
    for(i=0;i<d;i++) {
        UF.Merge(X[i], Y[i]);
        vector<int> V;
        for(j=0;j<N;j++) {
            if(UF.root[j] < 0) {
                V.push_back(-UF.root[j]);
            }
        }
        sort(V.begin(),V.end(),[](int x, int y) {return x>y;});
        int ans = 0;
        for(j=0;j<cnt+1;j++) ans += V[j];
        cout << ans-1 << '\n';
    }
}