#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (1<<18) + 1;
struct Node{
    ll val;
    int lef;
    int rig;
    int mask;
};

Node T[N * 2 + 512];

void push(int node, int cl, int cr){
    int len = (cr - cl + 1);
    if((T[node].mask & len) == len)
        swap(T[node].lef, T[node].rig);
    if(cl != cr){
        T[T[node].lef].mask ^= T[node].mask;
        T[T[node].rig].mask ^= T[node].mask;
    }
    T[node].mask = 0;
}

void upd(int node, int cl, int cr, int pos, int v){
    push(node, cl, cr);
    if(cl == cr){
        T[node].val = v;
        return;
    }
    int mid = (cl + cr) / 2;
    if(mid >= pos)
        upd(T[node].lef, cl, mid, pos, v);
    else
        upd(T[node].rig, mid + 1, cr, pos, v);
    T[node].val = T[T[node].lef].val + T[T[node].rig].val;
}

ll get(int node, int cl, int cr, int tl, int tr){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return 0;
    if(cl >= tl && cr <= tr){
        return T[node].val;
    }
    int mid = (cl + cr) / 2;
    return get(T[node].lef, cl, mid, tl, tr) + get(T[node].rig, mid + 1, cr, tl, tr);
}

int in[N];

void build(int node, int cl, int cr){
    if(cl == cr){
        T[node].val = in[cl];
        return;
    }
    T[node].lef = node * 2;
    T[node].rig = node * 2 + 1;
    int mid = (cl + cr) / 2;
    build(node * 2, cl, mid);
    build(node * 2 + 1, mid + 1, cr);
    T[node].val = T[node * 2].val + T[node * 2 + 1].val;
}

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    int m = (1 << n);
    for(int i = 1; i <= m ; i ++ ){
        cin >> in[i];
    }
    build(1, 1, m);
    int typ, l, r;
    int k;
    for(int tc = 1; tc <= q; tc ++ ){
        cin >> typ;
        if(typ == 1){
            cin >> l >> r;
            upd(1, 1, m, l, r);
        }
        else if(typ == 2){
            cin >> k;
            for(int i = k ; i >= 1; i -- ){
                T[1].mask ^= (1 << i);
            }
        }
        else if(typ == 3){
            cin >> k;
            T[1].mask ^= (1 << (k + 1));
        }
        else{
            cin >> l >> r;
            cout << get(1, 1, m, l, r) << "\n";
        }

    }
    return 0;
}