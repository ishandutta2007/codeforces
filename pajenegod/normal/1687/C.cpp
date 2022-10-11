// NOT MY CODE: https://codeforces.com/contest/1687/submission/159407748

#include<bits/stdc++.h>
// #include<atcoder/convolution>
using namespace std;
// using namespace atcoder;
 
struct UnionFind{
    vector<int> parent;
    vector<int> max_;
    UnionFind(int n){
        parent.assign(n, -1);
        max_.assign(n, -1);
        for(int i = 0; i < n; i++) max_[i] = i;
    }
 
    int find(int x){
        if(parent[x] < 0) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
 
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y){
            return;
        }
        if(parent[x] > parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        if(max_[y] > max_[x]) max_[x] = max_[y];
    }
};
 
void solve(){    
    int n, m;
    cin >> n >> m;
    vector<long long> A(n), B(n);
    vector<long long> cuma(n + 1), cumb(n + 1);
    cuma[0] = 0;
    cumb[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        cuma[i + 1] = cuma[i] + A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> B[i];
        cumb[i + 1] = cumb[i] + B[i];
    }
    if(cuma[n] != cumb[n]){
        int l, r;
        for(int i = 0; i < m; i++) cin >> l >> r;
        cout << "NO\n";
        return;
    }
    vector<vector<int>> vec(n + 1, vector<int>());
    vector<int> cnt(m, 0);
    vector<int> L(m), R(m);
    for(int i = 0; i < m; i++){
        cin >> L[i] >> R[i];
        L[i]--;
        vec[L[i]].push_back(i);
        vec[R[i]].push_back(i);
    }
 
    UnionFind UF(n + 1);
    stack<int> st;
    vector<bool> tf(n + 1, false);
    for(int i = 0; i <= n; i++){
        if(cuma[i] == cumb[i]){
            tf[i] = true;
            if(i != n) UF.unite(i, i + 1);
            for(auto j:vec[i]){
                cnt[j]++;
                if(cnt[j] == 2) st.push(j);
            }
        }
    }
    while(!st.empty()){
        int i = st.top();
        st.pop();
        int l = L[i];
        int r = R[i];
        while(1){
            l = UF.max_[UF.find(l)];
            if(l >= r) break;
            UF.unite(l, l + 1);
            tf[l] = true;
            for(auto j:vec[l]){
                cnt[j]++;
                if(cnt[j] == 2) st.push(j);
            }
        }
    }
    for(auto t:tf){
        if(!t){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
 
    
 
 
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}