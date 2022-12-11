#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)3e5 + 9;

struct Node{    
    ll value;
    ll lazy;
};

const ll inf = (ll)1e18;

Node Tree[N * 4 + 12];

void push(int node, int cl, int cr){
    Tree[node].value += Tree[node].lazy;
    if(cl != cr){
        Tree[node * 2].lazy += Tree[node].lazy;
        Tree[node * 2 + 1].lazy += Tree[node].lazy;
    }
    Tree[node].lazy = 0;
}

void update(int node, int cl, int cr, int tl, int tr, ll xv){
    push(node, cl, cr);
    if(cr < tl)
        return;
    if(cl > tr)
        return;
    if(cl >= tl && cr <= tr){
        Tree[node].lazy = xv;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    update(node * 2, cl , mid, tl, tr, xv);
    update(node * 2 + 1, mid + 1, cr, tl, tr, xv);
    Tree[node].value = max(Tree[node * 2].value, Tree[node * 2 + 1].value);
}

ll query(int node, int cl, int cr, int tl, int tr){
    push(node, cl, cr);
    if(cr < tl)
        return -inf;
    if(cl > tr)
        return -inf;
    if(cl >= tl && cr <= tr){
        return Tree[node].value;
    }
    int mid = (cl + cr) / 2;
    return max(query(node * 2, cl, mid, tl, tr),
               query(node * 2 + 1, mid + 1, cr, tl, tr));
}

ll sq(ll x){  
    return x * x;
}

int main(){
    fastIO;
    int n;
    ll a;
    cin >> n >> a;
    ll d[n], c[n];
    ll gp[n];
    for(int i = 0 ; i < n ; i ++ ){
        cin >> d[i] >> c[i];
    }
    for(int i = 0 ; i +1 < n ; i ++ ){
        gp[i] = sq(d[i + 1] - d[i]);
    }
    gp[n-1] = 0;
    ll res = 0;
    ll cur;
    stack<pii> ff;
    int ls;
    ll gap;
    ll pvl;
    for(int i = 0 ; i < n ; i ++ ){
        update(1, 0, n-1, 0, i, a);
        update(1, 0, n-1, 0, i, -c[i]);
        cur = query(1, 0, n-1, 0, i);
        res = max(res, cur);
        if(i==n-1)
            continue;
        gap = gp[i];
        update(1,0,n-1,i,i,-gap);
        ls = i;
        while(!ff.empty() && gap > ff.top().fi){
            update(1, 0, n - 1, ff.top().se, ls - 1, ff.top().fi - gap);
            ls = ff.top().se;
            ff.pop();
        }
        ff.push(mp(gap, ls));
    }
    cout << res << "\n";
    return 0;
}