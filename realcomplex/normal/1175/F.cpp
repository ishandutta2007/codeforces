#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 100;

struct Node{
    pii cnt;
    int lazy;
};

Node T[N * 4 + 512];

void push(int node, int cl, int cr){
    T[node].cnt.fi += T[node].lazy;
    if(cl != cr){
        T[node * 2].lazy += T[node].lazy;
        T[node * 2 + 1].lazy += T[node].lazy;
    }
    T[node].lazy = 0;
}


Node unite(Node A, Node B){
    Node sol;
    sol.lazy = 0;
    sol.cnt = A.cnt;
    if(B.cnt.fi < A.cnt.fi)
        sol.cnt = B.cnt;
    else if(B.cnt.fi == A.cnt.fi)
        sol.cnt.se += B.cnt.se;
    return sol;
}

void update(int node, int cl, int cr, int tl, int tr, int v){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return;
    if(cl >= tl && cr <= tr){
        T[node].lazy = v;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    update(node * 2, cl, mid, tl, tr, v);
    update(node * 2 + 1, mid + 1, cr, tl, tr, v);
    T[node] = unite(T[node * 2], T[node * 2 + 1]);
}

Node get(int node, int cl, int cr, int tl, int tr){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return {mp((int)1e9, 0),0};
    if(cl >= tl && cr <= tr){
        return T[node];
    }
    int mid = (cl + cr) / 2;
    return unite(get(node*2,cl,mid,tl,tr),get(node*2+1,mid+1,cr,tl,tr));
}

int last[N];

void build(int node, int cl, int cr){
    T[node].cnt = mp(0,cr-cl+1);
    if(cl != cr){
        int mid = (cl + cr) / 2;
        build(node * 2, cl, mid);
        build(node * 2 + 1, mid + 1, cr);
    }
}

int main(){
    fastIO;
    int n;
    cin >> n;
    int st = 1;
    int a;
    vector<pii> mx;
    int las;
    int nx;
    ll soln = 0;
    Node gg;
    build(1, 1, n);
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        st = max(st,last[a]+1);
        update(1, 1, n, 1, i, -1);
        las = i;
        while(!mx.empty() && a >= mx.back().se){
            nx = mx.back().fi;
            update(1, 1, n, nx, las - 1,a-mx.back().se);
            mx.pop_back();
            las = nx;
        }
        update(1, 1, n, i, i, a);
        gg = get(1, 1, n, st, i);
        if(gg.cnt.fi == 0) soln += gg.cnt.se;
        mx.push_back(mp(las, a));
        last[a]=i;
    }
    cout << soln << "\n";
    return 0;
}