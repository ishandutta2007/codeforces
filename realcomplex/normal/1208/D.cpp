#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;

struct Node{    
    ll value;
    ll lazy;
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

void update(int node, int cl, int cr, int tl, int tr, ll vl){
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
    int mid= (cl + cr) / 2;
    update(node * 2, cl, mid, tl, tr, vl);
    update(node * 2 + 1, mid + 1, cr, tl, tr, vl);
    T[node].value = min(T[node * 2].value, T[node * 2 + 1].value);
}

int query(int node, int cl, int cr){
    if(cl==cr)
        return cl;
    int mid = (cl + cr) / 2;
    push(node*2, cl, mid);
    push(node*2+1,mid+1,cr);
    if(T[node*2+1].value == 0){
        return query(node * 2 + 1, mid + 1, cr);
    }
    else{
        return query(node * 2, cl, mid);
    }
    
}

int res[N];

const ll inf = (ll)1e18;

int main(){
    fastIO;
    int n;
    cin >> n;
    ll x;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> x;
        update(1, 0, n - 1, i, i, x);
    }
    int pos;
    for(int i = 0 ; i < n  ; i ++ ){
        pos = query(1, 0, n-1);
        res[pos] = i+1;
        if(pos + 1 != n){
            update(1, 0, n - 1, pos + 1, n - 1, -(i+1));
        }
        update(1,0,n-1,pos,pos,inf);
    }
    for(int i = 0 ; i < n ; i ++ )
        cout << res[i] << " ";
    return 0;   
}