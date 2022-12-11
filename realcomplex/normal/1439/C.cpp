#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node{
    ll val;
    ll sum;
    ll lzy;
};

const int N = (int)2e5 + 10;

Node T[N * 4 + 512];
ll A[N];

void build(int node, int cl, int cr){
    if(cl == cr){
        T[node].val = A[cl];
        T[node].sum = A[cl];
        return ;
    }
    int mid = (cl + cr) / 2;
    build(node * 2, cl, mid);
    build(node * 2 + 1, mid + 1, cr);
    T[node].val = T[node * 2 + 1].val;
    T[node].sum = T[node * 2].sum + T[node * 2 + 1].sum;
}

void push(int node, int cl, int cr){
    if(T[node].lzy != 0){
        T[node].val = T[node].lzy;
        T[node].sum = (cr - cl + 1) * 1ll * T[node].lzy;
        if(cl != cr){
            T[node * 2].lzy = T[node].lzy;
            T[node * 2 + 1].lzy = T[node].lzy;
        }
        T[node].lzy = 0;
    }
}

void update(int node, int cl, int cr, int tl, int tr, ll val){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return;
    if(cl >= tl && cr <= tr){
        T[node].lzy = val;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    update(node * 2, cl, mid, tl, tr, val);
    update(node * 2 + 1, mid + 1, cr, tl, tr, val);
    T[node].sum = T[node * 2].sum + T[node * 2 + 1].sum;
    T[node].val = T[node * 2 + 1].val;
}

int get(int node, int cl, int cr, int id, ll x){ // i >= id && Ai <= x
    if(cr < id || T[node].val > x) return -1;
    int mid = (cl + cr) / 2;
    if(cl != cr){
        push(node * 2, cl, mid);
        push(node * 2 + 1, mid + 1, cr);
    }
    if(cl >= id){
        if(cl == cr) return cl;
        if(T[node * 2].val <= x) return get(node * 2, cl, mid, id, x);
        else return get(node * 2 + 1, mid + 1, cr, id, x);
    }
    int pa = get(node * 2, cl, mid, id, x);
    if(pa != -1) return pa;
    return get(node * 2 + 1, mid + 1, cr, id, x);
}

ll current;
int last_id;
bool go;

void big(int node, int cl, int cr, int id, ll sum){
    if(node == 1){
        current = 0;
        last_id = id;
        go = true;
    }
    if(!go) return;
    if(cr < id) return;
    if(cl == cr){
        if(current + T[node].sum <= sum){
            current += T[node].sum;
            last_id = cr;
        }
        else{
            go=false;
        }
        return;
    }
    int mid = (cl + cr) / 2;
    push(node * 2, cl, mid);
    push(node * 2 + 1, mid + 1, cr);
    if(cl >= id){
        if(current + T[node * 2].sum <= sum){
            current += T[node * 2].sum;
            last_id = mid;
            big(node * 2 + 1, mid + 1, cr, id, sum);
        }
        else{
            big(node * 2, cl, mid, id, sum);
        }
        return;
    }
    big(node * 2, cl, mid, id, sum);
    big(node * 2 + 1, mid + 1, cr, id, sum);
}
ll calc(int node, int cl, int cr, int tl, int tr){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return 0ll;
    if(cl >= tl && cr <= tr){
        return T[node].sum;
    }
    int mid = (cl + cr) / 2;
    return calc(node * 2, cl, mid, tl, tr) + calc(node * 2 + 1, mid + 1, cr, tl, tr);
}

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    build(1, 1, n);
    int segm = 0;
    int typ;
    int x;
    ll y;
    int id;
    int nex;
    ll soln;
    ll comp;
    ll ccy;
    int sax;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> typ;
        if(typ == 1){
            cin >> x >> y;
            id = get(1, 1, n, 1, y);
            if(id <= x && id != -1){
                update(1, 1, n, id, x, y);
            }
        }
        else{
            cin >> x >> y;

            sax = x;
            ccy = y;
            soln = 0;
            segm = 0;
            while(x <= n){
                x = get(1, 1, n, x, y);
                if(x == -1) break;
                big(1, 1, n, x, y);
                nex = last_id;
                y -= current;
                soln += nex - x + 1;
                x = nex + 1;
                segm ++ ;
            }

            cout << soln << "\n";

        }
    }
    return 0;
}