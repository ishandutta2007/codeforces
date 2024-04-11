#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> A;
vector<vector<int>> ans;
vector<int> idx;
inline int id(int n) {
    return lower_bound(idx.begin(),idx.end(),n)-idx.begin();
}
int sum[200005];
struct Edge {
    int to, cnt;
    int x, y;
    Edge *dual;
    Edge():Edge(-1,0, -1, -1) {}
    Edge(int to1, int cnt1, int x1, int y1):to(to1),cnt(cnt1),x(x1),y(y1),dual(nullptr) {}
};
vector<vector<Edge*>>adj;
vector<bool> vis;
void euler(int c, int cnt) {
    while(adj[c].size()) {
        auto e = adj[c].back();
        if(e->cnt > 0) {
            e->cnt--;
            e->dual->cnt--;
            ans[e->x][e->y] = cnt % 2;
            euler(e->to, cnt+1);
        }
        else adj[c].pop_back();
    }
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int M;
    cin >> M;
    int i, j, a, b, c, k;
    A.resize(M);
    ans.resize(M);
    for(i=0;i<M;i++) {
        cin >> a;
        A[i].resize(a);
        ans[i].resize(a);
        fill(ans[i].begin(),ans[i].end(),-1);
        for(j=0;j<a;j++) {
            cin >> A[i][j];
            idx.push_back(A[i][j]);
        }
    }
    sort(idx.begin(),idx.end());
    idx.erase(unique(idx.begin(),idx.end()),idx.end());
    adj.resize(M+idx.size());
    for(i=0;i<M;i++) {
        for(j=0;j<A[i].size();j++) A[i][j] = id(A[i][j]);
    }
    for(i=0;i<M;i++) {
        for(j=0;j<A[i].size();j++) sum[A[i][j]]++;
    }
    for(i=0;i<idx.size();i++) {
        if(sum[i]%2==1) {
            cout << "NO";
            return 0;
        }
    }
    for(i=0;i<M;i++) {
        map<int,vector<int>> M2;
        for(j=0;j<A[i].size();j++) {
            M2[A[i][j]].push_back(j);
        }
        for(auto it = M2.begin();it != M2.end();it++) {
            if(it->second.size()%2==1) {
                Edge *e1 = new Edge(i, 1,i,it->second[it->second.size()-1]);
                Edge *e2 = new Edge(it->first+M, 1,i,it->second[it->second.size()-1]);
                e1->dual = e2;
                e2->dual = e1;
                adj[it->first+M].push_back(e1);
                adj[i].push_back(e2);
            }
            for(k=0;k+1<it->second.size();k+=2) {
                ans[i][it->second[k]] = 0;
                ans[i][it->second[k+1]] = 1;
            }
        }
    }
    for(i=0;i<M+idx.size();i++) euler(i, 0);
    cout << "YES\n";
    for(i=0;i<M;i++) {
        for(j=0;j<ans[i].size();j++) {
            cout << (ans[i][j]==0?'L':'R');
        }
        cout << '\n';
    }
}