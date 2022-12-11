#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

struct Node{
    ll val;
    ll lzy;
};

Node T[N * 4 + 512];

void push(int node, int cl, int cr){
    T[node].val += T[node].lzy;
    if(cl != cr){
        T[node * 2].lzy += T[node].lzy;
        T[node * 2 + 1].lzy += T[node].lzy;
    }
    T[node].lzy = 0;
}

void update(int node, int cl, int cr, int tl, int tr, ll v){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return;
    if(cl >= tl && cr <= tr){
        T[node].lzy += v;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    update(node * 2, cl, mid, tl, tr, v);
    update(node * 2 + 1, mid + 1, cr, tl, tr, v);
    T[node].val = min(T[node * 2].val, T[node * 2 + 1].val);
}

ll get(int node, int cl, int cr, int tl, int tr){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return (ll)1e18;
    if(cl >= tl && cr <= tr)
        return T[node].val;
    int mid = (cl + cr) / 2;
    return min(get(node * 2, cl, mid, tl, tr),get(node * 2 + 1, mid + 1, cr, tl, tr));
}

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<pii> drink;
    ll x;
    int outp = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        if(x >= 0){
            update(1, 1, n, i, n, x);
            outp ++ ;
        }
        else
            drink.push_back(mp(-x, i));
    }
    sort(drink.begin(), drink.end());
    for(auto x : drink){
        if(get(1, 1, n, x.se, n) >= x.fi){
            update(1, 1, n, x.se, n, -x.fi);
            outp ++ ;
        }
    }
    cout << outp << "\n";
    return 0;
}