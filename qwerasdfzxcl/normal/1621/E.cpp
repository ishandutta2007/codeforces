#include <bits/stdc++.h>
#define int long long

typedef long long ll;
typedef __int128 l128;
using namespace std;
struct Frac{
    ll x, y;
    bool isa;
    Frac(){}
    Frac(ll _x, ll _y, bool _isa){
        assert(_y>0);
        ll g = __gcd(_x, _y);
        x = _x/g, y = _y/g;
        isa = _isa;
    }
    bool operator<(const Frac &F) const{
        l128 tmp1 = (l128)x * F.y, tmp2 = (l128)y * F.x;
        if (tmp1==tmp2) return isa<F.isa;
        return tmp1<tmp2;
    }
    bool operator==(const Frac &F) const{
        return x==F.x && y==F.y && isa==F.isa;
    }
};

struct Node{
    int suf, sum;
    Node(){}
    Node(int _suf, int _sum): suf(_suf), sum(_sum) {}
};

struct Seg{
    Node tree[1201200*2];
    int sz;
    Node combine(Node &x, Node &y){
        return Node(max(y.suf, x.suf+y.sum), x.sum+y.sum);
    }
    void init(int n){
        sz = 1;
        while(sz<n) sz <<= 1;
        fill(tree, tree+sz*2, Node(0, 0));
    }
    void update(int x, int val){
        x += sz;
        tree[x].sum += val;
        //if (x==10) printf("x: %d\n", tree[x].sum);
        tree[x].suf = max(tree[x].sum, 0LL);
        for(x>>=1;x;x>>=1) tree[x] = combine(tree[x<<1], tree[x<<1|1]);
    }
    Node query(int l, int r){
        Node retl = Node(0, 0), retr = Node(0, 0);
        for (l+=sz, r+=sz;l<r;l>>=1,r>>=1){
            if (l&1){
                retl = combine(retl, tree[l]);
                l++;
            }
            if (r&1){
                --r;
                retr = combine(tree[r], retr);
            }
        }
        return combine(retl, retr);
    }
}tree;
vector<Frac> V;
int a[100100];
ll sum[100100];
vector<int> b[100100];

int get_idx(ll x, ll y, ll z){
    int ret = lower_bound(V.begin(), V.end(), Frac(x, y, z)) - V.begin();
    return ret;
}

void solve(){
    int n, m;
    scanf("%lld %lld", &n, &m);
    V.clear();

    for (int i=0;i<n;i++){
        scanf("%lld", a+i);
        V.emplace_back(a[i], 1, 1);
    }

    for (int i=0;i<m;i++){
        b[i].clear();
        int sz;
        scanf("%lld", &sz);

        ll S = 0;
        for (int j=0;j<sz;j++){
            int x;
            scanf("%lld", &x);
            b[i].push_back(x);
            S += x;
        }
        sum[i] = S;
        V.emplace_back(S, sz, 0);
        for (int j=0;j<sz;j++) V.emplace_back(S-b[i][j], sz-1, 0);
    }

    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    tree.init(V.size());
    //printf("sz: %d\n", tree.sz);

    for (int i=0;i<n;i++){
        int idx = get_idx(a[i], 1, 1);
        tree.update(idx, -1);
    }
    for (int i=0;i<m;i++){
        int idx = get_idx(sum[i], b[i].size(), 0);
        tree.update(idx, 1);
    }

    /*printf("\n");
                for (int k=0;k<(int)V.size();k++){
                    printf("%lld %lld %d: %d %d\n", V[k].x, V[k].y, V[k].isa, tree.tree[k+tree.sz].sum, tree.tree[k+tree.sz].suf);
                }*/

    int ans;
    for (int i=0;i<m;i++){
        int idx = get_idx(sum[i], b[i].size(), 0);
        tree.update(idx, -1);

        for (int j=0;j<(int)b[i].size();j++){
            int idx2 = get_idx(sum[i]-b[i][j], b[i].size()-1, 0);
            tree.update(idx2, 1);

            auto T = tree.tree[1];
            if (T.suf>0) ans = 0;
            else ans = 1;

            printf("%lld", ans);

            if (false){
                printf("\n");
                for (int k=0;k<(int)V.size();k++){
                    printf("%lld %lld %lld: %lld %lld\n", V[k].x, V[k].y, V[k].isa, tree.tree[k+tree.sz].sum, tree.tree[k+tree.sz].suf);
                }
                printf("%lld %lld\n", T.suf, T.sum);
            }

            tree.update(idx2, -1);

        }
        tree.update(idx, 1);
    }

    printf("\n");
}

signed main(){
    int t;
    scanf("%lld", &t);
    while(t--){
        solve();
    }
    return 0;
}