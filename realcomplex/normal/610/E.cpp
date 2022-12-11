#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node{
    int val[10][10];
    int lzy;
    int fir_el;
    int las_el;
};

const int N = (int)2e5 + 9;
Node T[(1 << 19) + 34]; // ??????
vector<int> y;

void join(Node &res, Node &a, Node &b){
    for(int i = 0 ; i < 10; i ++ ) for(int j = 0 ; j < 10 ; j ++) res.val[i][j] = a.val[i][j] + b.val[i][j];
    res.fir_el = a.fir_el;
    res.las_el = b.las_el;
    res.val[a.las_el][b.fir_el] ++ ;
}

void build(int node, int cl, int cr){
    for(int i = 0 ; i < 10 ; i ++ ) for(int j = 0 ; j < 10; j ++ )
        T[node].val[i][j] = 0;
    T[node].lzy = -1;
    if(cl == cr){
        T[node].fir_el = y[cl];
        T[node].las_el = y[cr];
        return;
    }
    int mid = (cl + cr) / 2;
    build(node * 2, cl, mid);
    build(node * 2 + 1, mid + 1, cr);
    join(T[node], T[node * 2], T[node * 2 + 1]);
}

void push(int node, int cl, int cr){
    if(T[node].lzy == -1)
        return;
    for(int i = 0 ; i < 10 ; i ++ ) for(int j = 0 ; j < 10 ; j ++ )
        T[node].val[i][j] = 0;
    T[node].fir_el = T[node].lzy;
    T[node].las_el = T[node].lzy;
    T[node].val[T[node].lzy][T[node].lzy] = cr - cl;
    if(cl != cr){
        T[node * 2].lzy = T[node].lzy;
        T[node * 2 + 1].lzy = T[node].lzy;
    }
    T[node].lzy = -1;
}

void update(int node, int cl, int cr, int tl, int tr, int st){
    push(node, cl, cr);
    if(tl > cr)
        return;
    if(tr < cl)
        return;
    if(cl >= tl && cr <= tr){
        T[node].lzy = st;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr)/2;
    update(node * 2, cl, mid, tl, tr, st);
    update(node * 2 + 1, mid + 1, cr, tl, tr, st);
    join(T[node], T[node * 2], T[node * 2 + 1]);
}


int main(){
    fastIO;
    int n, m, k;
    cin >> n >> m >> k;
    char ip;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> ip;
        y.push_back(ip - 'a');
    }
    build(1, 0, n - 1);
    int typ;
    int cl, cr, si;
    string per;
    int res;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> typ;
        if(typ == 1){
            cin >> cl >> cr >> ip;
            -- cl, -- cr;
            update(1, 0, n - 1, cl, cr, ip - 'a');
        }
        else{
            cin >> per;
            res = 1;
            for(int i = 0 ; i < k ; i ++ ){
                for(int j = 0 ; j <= i ; j  ++ ){
                    res += T[1].val[per[i] - 'a'][per[j] - 'a'];
                }
            }
            cout << res << "\n";
        }

    }
    return 0;
}