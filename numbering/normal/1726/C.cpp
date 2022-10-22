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
        x = Find(x), y = Find(y);
        if(x==y) return;
        if(root[x]>root[y]) swap(x, y);
        root[x] += root[y];
        root[y] = x;
    }
};
int A[200005];
int B[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i ,j;
        string s;
        cin >> s;
        UnionFind UF(2*N);
        B[0] = 0;
        for(i=1;i<=2*N;i++) {
            B[i] = B[i-1] + (s[i-1] == '(' ? 1 : -1);
        }
        for(i=0;i<=2*N;i++) A[i] = -1;
        for(i=0;i<2*N;i++) {
            if(s[i]=='(') {
                if(i && s[i-1] == ')') UF.Merge(i-1, i);
                A[B[i]] = i;
            }
            else {
                UF.Merge(A[B[i+1]], i);
            }
        }
        set<int> S;
        for(i=0;i<2*N;i++) S.insert(UF.Find(i));
        cout << S.size() <<'\n';
    }
}