#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

const ll N = 1e5 + 500;
const ll LOG = 59;
const ll OFF = (1LL << LOG);

ll lo, hi, all , n, q, x, y, ans, p[N];

struct node{
    node *l,*r,*par;
    ll sm, sol;
    ll cnt, rlcnt;
    node(){
        sm = 0, cnt = 0;
        l = NULL, r = NULL, par = NULL;
    }
}*root;

void mrg(node *x){
    if(x -> l == NULL && x -> r == NULL) {
        x -> sm = 0;
        x -> cnt = 0;
        x -> sol = 0;
        return;
    }
    if(x -> r == NULL){
        x -> sm = x -> l -> sm;
        x -> cnt = x -> l -> cnt;
        x -> sol = x -> l -> sol;
        return;
    }
    if(x -> l == NULL){
        x -> sm = x -> r -> sm;
        x -> cnt = x -> r -> cnt;
        x -> sol = x -> r -> sol;
        return;
    }
    x -> sol = (x -> l -> cnt) * (x -> r -> sm) - (x -> r -> cnt) * (x -> l -> sm) + x -> l -> sol + x -> r -> sol;
    x -> sm = x -> l -> sm + x -> r -> sm;
    x -> cnt = x -> l -> cnt + x -> r -> cnt;
}

void update(ll x , ll del = 0){
    x += OFF;
    node *cur = root;
    for(ll j = LOG;j>=0;j--){
        if(!(x & (1LL << j))) {
            if(cur -> l == NULL){
                cur -> l = new node();
                cur -> l -> par = cur;
            }
            cur = cur->l;
        }
        else {
            if(cur -> r == NULL){
                cur -> r = new node();
                cur -> r -> par = cur;
            }
            cur = cur->r;
        }
        if(cur == NULL) cur = new node();
    }
    if(!del){
        cur -> cnt = 1;
        cur -> sm = x;
        cur -> sol = 0;
    }
    else{
        cur -> cnt = 0;
        cur -> sm = 0;
        cur -> sol = 0;
    }
    cur = cur -> par;
    while(cur  != NULL){
        mrg(cur);
        cur = cur -> par;
    }
}

void query(node* x, ll a = 0, ll b = 2 * OFF - 1, ll lf = 0, ll ri = 0){
    if(x == NULL) return;
    if(lo <= a && b <= hi){
        ans += x -> sol;
        ans += (lf - ri) * x -> sm;
        return;
    }
    if(a > hi || b < lo) return;
    query(x->l, a, (a + b) / 2, lf, ri + (x -> r != NULL ? x -> r -> rlcnt : 0));
    query(x->r, (a + b) / 2  + 1, b, lf + (x -> l != NULL ? x -> l -> rlcnt : 0), ri );
}

void query2(node* x, ll a = 0, ll b = 2 * OFF - 1){
    if(x == NULL) return;
    if(lo <= a && b <= hi){
        x -> rlcnt = x->cnt;
        return;
    }
    if(a > hi || b < lo) {
        x -> rlcnt = 0;
        return;
    }
    query2(x->l, a, (a + b) / 2);
    query2(x->r, (a + b) / 2  + 1, b );
    x -> rlcnt = (x -> l != NULL ? x -> l -> rlcnt : 0) + (x -> r != NULL ? x -> r -> rlcnt : 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    root = new node();
    cin >> n;
    for(ll i = 0;i<n;i++){
        ll x;cin >> x;p[i] = x;
        update(x);
    }
    cin >> q;
    for(ll i = 0;i<q;i++){
        ll typ;cin >> typ;
        if(typ == 1){
            cin >> x >> y;x--;
            update(p[x], 1);
            update(p[x] + y);
            p[x] += y;
        }
        else{
            cin >> lo >> hi;
            lo += OFF, hi += OFF;
            ans = 0, query2(root), query(root);
            cout << ans << "\n";
        }
    }
}