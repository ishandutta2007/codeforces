#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Scan and Debug
void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f,R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)

const int MAX = 1e5 + 1;
int n, q, bt, bn,
    sz[MAX], pars[MAX], best[MAX];
vector<int> matrix[MAX], dis[MAX];
bool blocked[MAX];

int gsz(int cur, int par) {
    sz[cur] = 1;
    for (int adj : matrix[cur]) 
        if ((adj ^ par) && !blocked[adj])
            sz[cur] += gsz(adj, cur);
    return sz[cur];
}

int gcentroid(int cur, int par, int half) {
    for (int adj : matrix[cur]) 
        if ((adj ^ par) && !blocked[adj] && sz[adj] > half)
            return gcentroid(adj, cur, half);
    return cur;
}

void dfs(int cur, int par, int cdis) {
    dis[cur].push_back(cdis);
    for (int adj : matrix[cur])
        if ((adj ^ par) && !blocked[adj])
            dfs(adj, cur, cdis + 1);
}

int decomp(int cur, int par) {
    gsz(cur, par);
    if (sz[cur] == 1) {
        dis[cur].push_back(0);
        return cur;
    }

    int centroid = gcentroid(cur, par, sz[cur] >> 1);
    dfs(centroid, -1, 0);

    blocked[centroid] = true;
    for (int adj : matrix[centroid])
        if (!blocked[adj])
            pars[decomp(adj, centroid)] = centroid;
    
    return centroid;
}

void upd(int nd) {
    int lv = dis[nd].size() - 1;
    for (int cur = nd; cur != -1; cur = pars[cur], lv--)
        best[cur] = min(best[cur], dis[nd][lv]);
}

int query(int nd) {
    int cbest = 0x3f3f3f3f, lv = dis[nd].size() - 1;
    for (int cur = nd; cur != -1; cur = pars[cur], lv--)
        cbest = min(cbest, dis[nd][lv] + best[cur]);
    return cbest;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    scan(n, q);

    for (int i = 0; i < n - 1; i++) {
        scan(bt, bn);
        matrix[bt].push_back(bn);
        matrix[bn].push_back(bt);
    }

    pars[decomp(1, -1)] = -1;

    memset(best, 0x3f, sizeof best);
    upd(1);

    for (int i = 0; i < q; i++) {
        scan(bt, bn);

        if (bt == 1)
            upd(bn);
        else
            cout << query(bn) << "\n";
    }
    

    return 0;
}