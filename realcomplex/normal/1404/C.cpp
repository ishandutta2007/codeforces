#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 100;

struct Node{
    int mx;
    int lazy;
};

Node T[N * 4 + 512];

void push(int node, int cl, int cr){
    T[node].mx += T[node].lazy;
    if(cl != cr){
        T[node * 2].lazy += T[node].lazy;
        T[node * 2 + 1].lazy += T[node].lazy;
    }
    T[node].lazy = 0;
}

void update(int node, int cl, int cr, int tl, int tr, int v){
    push(node, cl, cr);
    if(cr < tl || cl > tr)
        return;
    if(cl >= tl && cr <= tr){
        T[node].lazy = v;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    update(node * 2, cl, mid, tl, tr, v);
    update(node * 2 + 1, mid + 1, cr, tl, tr, v);
    T[node].mx = max(T[node * 2].mx, T[node * 2 + 1].mx);
}

int get(int node, int cl, int cr, int pos){
    push(node, cl, cr);
    if(cl == cr)
        return T[node].mx;
    int mid = (cl + cr) / 2;
    if(mid >= pos)
        return get(node * 2, cl, mid, pos);
    else
        return get(node * 2 + 1, mid + 1, cr, pos);
}

int big(int node, int cl, int cr, int v){
    if(cl == cr) return cl;
    int mid = (cl + cr) / 2;
    push(node * 2, cl, mid);

    push(node * 2 + 1, mid + 1, cr);

    if(T[node * 2 + 1].mx >= v)
        return big(node * 2 + 1, mid + 1, cr, v);
    else
        return big(node * 2, cl, mid, v);
}

int d[N];

vector<pii> qq[N];
int sol[N];

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    int a;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        d[i]=i-a;
        if(d[i] < 0)
            d[i] = (int)1e9;
    }
    int x, y;
    for(int i = 1; i <= q; i ++ ){
        cin >> x >> y;
        x++;
        y=n-y;
        qq[y].push_back(mp(x, i));
    }
    update(1, 0, n, 0, 0, (int)1e9);
    update(1, 0, n, 1, n, -1);
    int best;
    for(int i = 1; i <= n; i ++ ){
        update(1, 0, n, i, i, +1);
        best = big(1, 0, n, d[i]);
        update(1, 0, n, 0, best, +1);
        for(auto p : qq[i]){
            sol[p.se] = get(1, 0, n, p.fi);
        }
    }
    for(int i = 1; i <= q; i ++ )
        cout << sol[i] << "\n";
    return 0;
}