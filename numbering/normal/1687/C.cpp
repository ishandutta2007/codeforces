#include <bits/stdc++.h>
#define int long long
using namespace std;
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
        x = Find(x);
        y = Find(y);
        if(x==y) return;
        if(root[x]>root[y]) swap(x, y);
        root[x] += root[y];
        root[y] = x;
    }
};
int A[200005];
int B[200005];
int L[200005];
int R[200005];
int ord[200005];
typedef pair<int,int> P;
vector<vector<int>> adj;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, Q;
        cin >> N >> Q;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        for(i=0;i<N;i++) cin >> B[i];
        for(i=0;i<N;i++) A[i] -= B[i];
        B[0] = 0;
        for(i=1;i<=N;i++) B[i] = B[i-1] + A[i-1];
        set<int> S;
        for(i=1;i<=N;i++) {
            if(B[i]!=0) S.insert(i);
        }
        for(i=0;i<Q;i++) cin >> L[i] >> R[i];
        for(i=0;i<Q;i++) L[i]--;
        for(i=0;i<Q;i++) ord[i] = 0;
        queue<int> Qu;
        adj.clear();
        adj.resize(N+1);
        for(i=0;i<Q;i++) {
            if(B[L[i]]!=0) {
                adj[L[i]].push_back(i);
                ord[i]++;
            }
            if(B[R[i]]!=0) {
                adj[R[i]].push_back(i);
                ord[i]++;
            }
            if(ord[i]==0) Qu.push(i);
        }
        while(!Qu.empty()) {
            int c = Qu.front();
            Qu.pop();
            auto it = S.upper_bound(L[c]);
            while(it != S.end() && *it <= R[c]) {
                for(int n :adj[*it]) {
                    ord[n]--;
                    if(ord[n]==0) Qu.push(n);
                }
                auto it2 = it;
                it++;
                S.erase(it2);
            }
        }
        cout << (S.empty() ? "YES\n" : "NO\n");
    }
}