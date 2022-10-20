#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
constexpr ll INF = 1e18;
struct Seg{
    ll tree[1100000];
    void init(int i, int l, int r, ll *a){
        if (l==r) {tree[i] = a[l]; return;}
        int m = (l+r)>>1;
        init(i<<1, l, m, a); init(i<<1|1, m+1, r, a);
        tree[i] = min(tree[i<<1], tree[i<<1|1]);
    }
    int right_bound(int i, int l, int r, int x, ll val){
        if (r<x) return -1;
        if (l==r){
            if (tree[i]<val) return l;
            return -1;
        }
        if (x<=l && tree[i]>=val) return -1;
        int m = (l+r)>>1;
        int tmp = right_bound(i<<1, l, m, x, val);
        if (tmp==-1) return right_bound(i<<1|1, m+1, r, x, val);
        return tmp;
    }
}tree1, tree2;
vector<int> pos[2][300300];
ll S[2][300300], T[300300], a[300300];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%lld", a+i);

    vector<ll> X[2];

    for (int i=1;i<=n;i++){
        if (i&1) S[1][i] = (-S[0][i-1])+a[i], S[0][i] = INF;
        else S[1][i] = INF, S[0][i] = -S[1][i-1]+a[i];
        if (i&1) T[i] = T[i-1] + a[i];
        else T[i] = T[i-1] - a[i];

        X[0].push_back(S[0][i]);
        X[1].push_back(S[1][i]);
    }
    tree1.init(1, 1, n, S[0]);
    tree2.init(1, 1, n, S[1]);

    sort(X[0].begin(), X[0].end()); X[0].erase(unique(X[0].begin(), X[0].end()), X[0].end());
    sort(X[1].begin(), X[1].end()); X[1].erase(unique(X[1].begin(), X[1].end()), X[1].end());
    for (int i=1;i<=n;i++){
        int idx1 = lower_bound(X[0].begin(), X[0].end(), S[0][i])-X[0].begin();
        int idx2 = lower_bound(X[1].begin(), X[1].end(), S[1][i])-X[1].begin();
        pos[0][idx1].push_back(i);
        pos[1][idx2].push_back(i);
    }

    ll ans = 0;
    for (int i=1;i<=n;i++){
        int val1 = tree1.right_bound(1, 1, n, i, -T[i-1]);
        int val2 = tree2.right_bound(1, 1, n, i, T[i-1]);
        if (val1==-1) val1 = n+1;
        if (val2==-1) val2 = n+1;

        //printf("%d %lld: %d %d\n", i, T[i-1], val1, val2);

        int mxpos = min(val1-1, val2-1);
        int idx1 = lower_bound(X[0].begin(), X[0].end(), -T[i-1])-X[0].begin();
        int idx2 = lower_bound(X[1].begin(), X[1].end(), T[i-1])-X[1].begin();

        if (X[0][idx1]==-T[i-1]) ans += upper_bound(pos[0][idx1].begin(), pos[0][idx1].end(), mxpos) - lower_bound(pos[0][idx1].begin(), pos[0][idx1].end(), i);
        if (X[1][idx2]==T[i-1]) ans += upper_bound(pos[1][idx2].begin(), pos[1][idx2].end(), mxpos) - lower_bound(pos[1][idx2].begin(), pos[1][idx2].end(), i);
        //printf(" %lld\n", ans);
    }
    printf("%lld\n", ans);

    for (int i=0;i<(int)X[0].size();i++) pos[0][i].clear();
    for (int i=0;i<(int)X[1].size();i++) pos[1][i].clear();
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}