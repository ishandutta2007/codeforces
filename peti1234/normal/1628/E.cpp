#include <bits/stdc++.h>

using namespace std;
const int c=300005, k=20;
int n, m, szint[c], fel[c][k], ert[c][k], rmq[c][k], lg[c];
bool v[c];
vector<pair<int, int> > sz[c];
set<pair<int, int> > s;
priority_queue<int> q[2];
void dfs(int a) {
    v[a]=true;
    for (int i=1; i<k; i++) {
        int s=fel[a][i-1];
        fel[a][i]=fel[s][i-1];
        ert[a][i]=max(ert[a][i-1], ert[s][i-1]);
    }
    for (auto p:sz[a]) {
        int x=p.first, y=p.second;
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x][0]=a, ert[x][0]=y;
            dfs(x);
        }
    }
}
int lca(int a, int b) {
    if (a==0 || b==0 || a==n+1 || b==n+1) return 0;
    int ans=0;
    if (szint[a]<szint[b]) {
        swap(a, b);
    }
    for (int i=k-1; i>=0; i--) {
        if (szint[fel[a][i]]>=szint[b]) {
            ans=max(ans, ert[a][i]);
            a=fel[a][i];
        }
    }
    if (a==b) {
        return ans;
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i]!=fel[b][i]) {
            ans=max({ans, ert[a][i], ert[b][i]});
            a=fel[a][i], b=fel[b][i];
        }
    }
    return max({ans, ert[a][0], ert[b][0]});
    return ans;
}
int ask(int l, int r) {
    if (l==r) {
        return 0;
    }
    int ert=lg[r-l];
    return max(rmq[l][ert], rmq[r-(1<<ert)][ert]);
}
void pb(int a, int b) {
    q[b].push(a);
}
void add(int l, int r, int id) {
    if (r<l) {
        return;
    }
    int kezd=0, veg=0;
    if (id==1) {
        s.insert({l, r});
    }
    auto it=s.find({l, r});
    it--;
    kezd=(*it).second;
    it++, it++;
    veg=(*it).first;
    pb(lca(kezd, l), id), pb(lca(r, veg), id);
    pb(lca(kezd, veg), 1-id);
    pb(ask(l, r), id);
    if (id==0) {
        s.erase({l, r});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back({b, c});
        sz[b].push_back({a, c});
    }
    szint[1]=1;
    dfs(1);
    for (int i=1; i<n; i++) {
        if (i>1) lg[i]=lg[i/2]+1;
        rmq[i][0]=lca(i, i+1);
    }
    for (int j=1; j<k; j++) {
        for (int i=1; i+(1<<j)<=n; i++) {
            rmq[i][j]=max(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
        }
    }
    s.insert({0, 0}), s.insert({n+1, n+1});
    q[1].push(0), q[0].push(-1);
    for (int i=1; i<=m; i++) {
        int id;
        cin >> id;
        if (id==1 || id==2) {
            int l, r, l2, r2;
            cin >> l >> r;
            l2=l, r2=r;
            auto it=s.upper_bound({l, 0});
            it--;
            while ((*it).first<=r) {
                auto it2=it;
                it++;
                int fi=(*it2).first, se=(*it2).second;
                if (se>=l) {
                    l2=min(l2, fi);
                    r2=max(r2, se);
                    add(fi, se, 0);
                }
            }
            if (id==1) {
                add(l2, r2, 1);
            } else {
                add(l2, l-1, 1);
                add(r+1, r2, 1);
            }
        }
        if (id==3) {
            int x;
            cin >> x;
            while (q[0].top()==q[1].top()) {
                q[0].pop(), q[1].pop();
            }
            int ans=q[1].top();
            for (auto p:s) {
                int y=p.first;
                if (1<=y && y<=n) {
                    ans=max(ans, lca(x, y));
                    break;
                }
            }
            cout << (ans==0 ? -1 : ans) << "\n";
        }
    }
    return 0;
}