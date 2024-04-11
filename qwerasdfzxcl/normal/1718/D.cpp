#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int p[300300], a[300300], s[300300], ans[300300];
int cnt[300300], MN, MX, noflag;

struct Seg{
    pair<int, int> tree[600600];
    int sz;
    void init(int n, int a[]){
        sz = n;
        for (int i=sz;i<sz*2;i++) tree[i] = {a[i-sz], i-sz};
        for (int i=sz-1;i;i--) tree[i] = max(tree[i<<1], tree[i<<1|1]);
    }
    int query(int l, int r){
        ++r;
        pair<int, int> ret = {0, 0};
        for (l+=sz, r+=sz;l<r;l>>=1, r>>=1){
            if (l&1) ret = max(ret, tree[l++]);
            if (r&1) ret = max(ret, tree[--r]);
        }
        return ret.second;
    }
}tree1;

struct Range{
    int first, second, idx;
    Range(){}
    Range(int _f, int _s, int _idx): first(_f), second(_s), idx(_idx) {}
    bool operator < (const Range &R) const{
        return idx < R.idx;
    }
};
vector<Range> R;


int dfs(int l, int r, int mx = 1e9){
    int mn = -1e9;
    int m = tree1.query(l, r);

    if (a[m]) mx = min(mx, a[m]), mn = max(mn, a[m]);

    if (m<r){
        int tmp = dfs(m+1, r, mx-1);
        mn = max(mn, tmp + 1);
    }
    if (l<m){
        int tmp = dfs(l, m-1, mx-1);
        mn = max(mn, tmp + 1);
    }

    if (mn > mx) noflag = 1;
    if (!a[m]) R.emplace_back(mn, mx, m);
    return mn;
}

bool cmpF(Range x, Range y){return x.first < y.first;}
bool cmpB(Range x, Range y){return x.second > y.second;}

void solveF(int n, int k){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    sort(R.begin()+1, R.end(), cmpF);
    fill(cnt+1, cnt+k+1, 0);

    int pt = 1;
    for (int i=1;i<=k-1;i++){
        while(pt<=k && R[pt].first <= s[i]){
            pq.emplace(R[pt].second, R[pt].idx);
            ++pt;
        }

        while(!pq.empty() && pq.top().first < s[i]) pq.pop();
        if (!pq.empty()){
            cnt[pq.top().second]++;
            pq.pop();
        }
        else noflag = 1;
    }

    sort(R.begin()+1, R.end());
    for (int i=1;i<=k;i++) if (!cnt[i]) MX = R[i].second;
}

void solveB(int n, int k){
    priority_queue<pair<int, int>> pq;
    sort(R.begin()+1, R.end(), cmpB);
    fill(cnt+1, cnt+k+1, 0);

    int pt = 1;
    for (int i=k-1;i;i--){
        while(pt<=k && R[pt].second >= s[i]){
            pq.emplace(R[pt].first, R[pt].idx);
            ++pt;
        }

        while(!pq.empty() && pq.top().first > s[i]) pq.pop();
        if (!pq.empty()){
            cnt[pq.top().second]++;
            pq.pop();
        }
        else noflag = 1;
    }

    sort(R.begin()+1, R.end());
    for (int i=1;i<=k;i++) if (!cnt[i]) MN = R[i].first;
}

void solve(){
    noflag = 0;
    int n, q, k = 0;
    scanf("%d %d", &n, &q);

    for (int i=1;i<=n;i++) scanf("%d", p+i);
    for (int i=1;i<=n;i++){
        scanf("%d", a+i);
        if (!a[i]) k++;
    }
    tree1.init(n+1, p);

    R.clear();
    R.emplace_back(1e9, -1e9, 0);
    dfs(1, n);
    sort(R.begin(), R.end());
    for (int i=1;i<(int)R.size();i++) R[i].idx = i;

    for (int i=1;i<=k-1;i++) scanf("%d", s+i);
    sort(s+1, s+k);

    solveF(n, k);
    solveB(n, k);
    //printf(" MN MX = %d %d\n", MN, MX);

    for (int i=1;i<=q;i++){
        int x;
        scanf("%d", &x);
        if (!noflag && MN <= x && x <= MX) printf("YES\n");
        else printf("NO\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}