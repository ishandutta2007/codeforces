#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)1e6 + 9;
const int K = (int)1e6;

struct Node{    
    int value;
    int lazy;
};

Node T[N * 4 + 512];

void push(int node, int cl, int cr){
    T[node].value += T[node].lazy;
    if(cl != cr){
        T[node * 2].lazy += T[node].lazy;
        T[node * 2 + 1].lazy += T[node].lazy;
    }
    T[node].lazy = 0;
}

void update(int node, int cl, int cr, int tl, int tr, int vl){
    push(node, cl, cr);
    if(cr < tl)
        return;
    if(cl > tr)
        return;
    if(cl >= tl && cr <= tr){
        T[node].lazy = vl;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    update(node * 2, cl, mid, tl, tr, vl);
    update(node * 2 + 1, mid + 1, cr, tl, tr, vl);
    T[node].value = max(T[node * 2].value,T[node * 2 + 1].value);
}

int ask(int node, int cl, int cr){
    if(T[node].value <= 0)
        return -1;
    if(cl == cr)
        return cl;
    int mid = (cl + cr) / 2;
    push(node * 2, cl, mid);
    push(node * 2 + 1, mid + 1, cr);
    if(T[node * 2 + 1].value > 0)
        return ask(node * 2 + 1, mid + 1, cr);
    else
        return ask(node * 2, cl, mid);
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
        update(1, 1, K, 1, a[i], +1);
    }
    for(int i = 0 ; i < m ; i ++ ){
        cin >> b[i];
        update(1, 1, K, 1, b[i], -1);
    }
    int q;
    cin >> q;
    int typ;
    int id;
    int x;
    for(int i = 0 ; i < q; i ++ ){
        cin >> typ >> id >> x;
        -- id;
        if(typ == 1){
            update(1, 1, K, 1, a[id], -1);
            a[id] = x;
            update(1, 1, K, 1, a[id], +1);
        }
        else{
            update(1, 1, K, 1, b[id], +1);
            b[id] = x;
            update(1, 1, K, 1, b[id], -1);
        }
        cout << ask(1, 1, K) << "\n";
    }
    return 0;
}