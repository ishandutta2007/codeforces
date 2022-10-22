#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int A[100005];
struct UnionFind {
    vector<int> root;
    UnionFind(int N) {
        root.resize(N);
        fill(root.begin(),root.end(),-1);
    }
    int Find(int n) {
        if(root[n]<0) return n;
        int r = Find(root[n]);
        root[n] = r;
        return r;
    }
    void Merge(int x, int y) {
        x = Find(x), y = Find(y);
        if(x==y) return;
        if(root[x]>root[y]) swap(x, y);
        root[x] += root[y];
        root[y] = x;
    }
};
int B[100005];
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i, j;
        UnionFind UF(N);
        for(i=0;i<N;i++) cin >> A[i];
        vector<array<int, 2>> V;
        for(i=0;i<N;i++) V.push_back({A[i], i});
        for(i=0;i<N;i++) B[i] = -1;
        sort(V.begin(),V.end());
        int cnt = 0;
        for(i=N-1;i>=0;i--) {
            int id = V[i][1];
            if(B[id]==-1) {
                B[id] = cnt;
                cnt++;
                if(A[id]==0) continue;
                int ck = 0;
                while(ck < V[i][0]) {
                    int v;
                    cout << "? " << id+1 << endl;
                    cin >> v;
                    v--;
                    if(B[v]==-1) {
                        B[v] = B[id];
                    }
                    else {
                        UF.Merge(B[v], B[id]);
                        break;
                    }
                    ck++;
                }
            }
        }
        cout << "! ";
        for(i=0;i<N;i++) {
            cout << UF.Find(B[i]) + 1 << ' ';
        }
        cout << endl;
    }
}