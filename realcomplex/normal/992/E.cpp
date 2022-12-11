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

struct Node{
    ll lazy;
    ll value;
};

const int N = (int)2e5 + 9;
Node T[N * 4];

void push(int node, int cl, int cr){
    T[node].value += (cr - cl + 1) * 1ll * T[node].lazy;
    if(cl != cr){
        T[node*2].lazy += T[node].lazy; 
        T[node*2+1].lazy += T[node].lazy;
    }
    T[node].lazy=0;
}

void update(int node, int cl, int cr, int tl, int tr, ll vl){
    push(node,cl,cr);
    if(cr < tl)
        return;
    if(cl > tr)
        return;
    if(cl >= tl && cr <= tr){
        T[node].lazy += vl;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    update(node * 2, cl, mid, tl, tr, vl);
    update(node * 2 + 1, mid + 1, cr, tl, tr, vl);
    T[node].value = T[node * 2].value + T[node * 2 + 1].value;
}

ll ask(int node, int cl, int cr, int tl, int tr){
    if(tl < 0)
        return 0ll;
    push(node, cl, cr);
    if(cr < tl)
        return 0ll;
    if(cl > tr)
        return 0ll;
    if(cl >= tl && cr <= tr){
        return T[node].value;
    }
    int mid = (cl + cr) / 2;
    return ask(node * 2, cl, mid, tl, tr) + ask(node * 2 + 1, mid + 1, cr, tl, tr);
}

const int K = 30;
set<int> id[K];

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    ll p[n];
    for(int i = 0 ; i < n; i ++ ){
        cin >> p[i];
        update(1, 0, n-1, i, n-1, p[i]);
        for(ll j = K-1; j >= 0 ; j -- ){
            if(p[i] >= (1ll << j)){
                id[j].insert(i);
                break;
            }
        }
    }
    int ii;
    ll di;
    int fin = -1;
    for(int i = 0 ; i < q; i ++ ){
        cin >> ii >> di;
        -- ii;
        update(1, 0, n-1, ii, n-1, -p[ii]);
        for(ll j = 0 ; j < K ; j ++ ){
            if(id[j].count(ii)) id[j].erase(ii);
        }
        p[ii] = di;
        update(1, 0, n-1, ii, n-1, p[ii]);
        for(ll j = K-1; j  >= 0 ; j -- ){
            if(p[ii] >= (1ll << j)){
                id[j].insert(ii);
                break;
            }
        }
        fin=-2;
        for(int j = 0 ; j < K ; j ++ ){
            if(id[j].empty())
                continue;
            auto it = id[j].begin();
            for(int z = 0 ;z < 2; z ++ ){
                if(it != id[j].end()){
                    if(p[*it] == ask(1,0,n-1,(*it)-1,(*it)-1)){
                        fin = (*it);
                    }
                    it ++ ;
                }
            }
        }
        if(p[0]==0)fin=0;
        cout << fin+1 << "\n";
    }
    return 0;
}