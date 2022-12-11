#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int M = N * 2 + 512;

struct Node{
    int val;
    int lazy;
};

Node T[M * 4 + 512];

void push(int node, int cl, int cr){
    T[node].val += T[node].lazy;
    if(cl != cr){
        T[node * 2].lazy += T[node].lazy;
        T[node * 2 + 1].lazy += T[node].lazy;
    }
    T[node].lazy = 0;
}

void upd(int node, int cl, int cr, int tl, int tr, int v){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return;
    if(cl >= tl && cr <= tr){
        T[node].lazy = v;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    upd(node * 2, cl, mid, tl, tr, v);
    upd(node * 2 + 1, mid + 1, cr, tl, tr, v);
    T[node].val = max(T[node * 2].val, T[node * 2 + 1].val);
}

int get(int node, int cl, int cr, int li, int ri){
    push(node, cl, cr);
    if(cr < li || cl > ri) return -(int)2e9;
    if(cl >= li && cr <= ri){
        return T[node].val;
    }
    int mid = (cl + cr) / 2;
    return max(get(node * 2, cl, mid, li, ri),get(node * 2 + 1, mid + 1, cr, li, ri));
}

int tree[M * 2 + 512];
int lim;

void updv(int node, int v){
    node += lim;
    tree[node] += v;
    node /= 2;
    while(node > 0){
        tree[node] += v;
        node /= 2;
    }
}

int qry(int l, int r){
    l += lim;
    r += lim;
    int ans = 0;
    while(l <= r){
        if(l % 2 == 1) ans += tree[l ++ ];
        if(r % 2 == 0) ans += tree[r -- ];
        l /= 2;
        r /= 2;
    }
    return ans;
}

int main(){
    fastIO;
    int n, k, m;
    cin >> n >> k >> m;
    int d = n * 2 + 1;
    lim = d;
    for(int i = 0 ; i < 4 * d + 512; i ++ ){
        T[i] = {-(int)1e9, 0};
    }
    set<pii> has;
    multiset<int> fsh;
    int x, y;
    int a;
    int cn;
    int pv;
    int ans;
    int qq;
    int cl;
    for(int i = 0 ; i < m; i ++ ){
        cin >> x >> y;
        a = y + abs(x - k);
        if(has.count(mp(x,y))){
            fsh.erase(fsh.find(a));
            cn = qry(a, a);
            if(cn == 1){
                pv = get(1, 1, d, a, a);
                upd(1, 1, d, a, a, -(int)pv - (int)1e9);
            }
            upd(1, 1, d, a + 1, d, +1);
            updv(a, -1);
            has.erase(mp(x,y));
        }
        else{
            fsh.insert(a);
            cn = get(1, 1, d, a, a);
            qq = qry(a, a);
            if(qq == 0){
                pv = qry(1, a - 1);
                upd(1, 1, d, a, a, -cn + a - (pv + 1));
            }
            upd(1, 1, d, a + 1, d, -1);
            updv(a, +1);
            has.insert(mp(x, y));
        }
        ans = n;
        ans = max(ans, T[1].val + (int)has.size());
        cout << ans-n << "\n";
    }
    return 0;
}