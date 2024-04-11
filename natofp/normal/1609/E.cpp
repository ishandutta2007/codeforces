#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

struct node{
    int a;
    int b;
    int c;
    int ab;
    int bc;
    int abc;
};

const int roz = (1 << 18);
node tree[roz];

node emp;

bool eq(node x, node y){
    return(x.a == y.a && x.b == y.b && x.c == y.c && x.ab == y.ab && x.bc == y.bc && x.abc == y.abc);
}

node merge(node L, node R){
    if(eq(L, emp)) return R;
    if(eq(R, emp)) return L;
    node res;
    res.a = L.a + R.a;
    res.b = L.b + R.b;
    res.c = L.c + R.c;
    res.ab = L.a + R.ab;
    res.ab = min(res.ab, L.ab + R.b);
    res.bc = L.b + R.bc;
    res.bc = min(res.bc, L.bc + R.c);
    res.abc = L.a + R.abc;
    res.abc = min(res.abc, L.ab + R.bc);
    res.abc = min(res.abc, L.abc + R.c);
    return res;
}

void upd(int pos, char val){
    pos += roz / 2;
    node cur = emp;
    cur.bc = cur.ab = cur.abc = 0;
    cur.a = cur.b = cur.c = 0;
    if(val == 'a') cur.a = 1;
    else if(val == 'b') cur.b = 1;
    else cur.c = 1;
    tree[pos] = cur;
    pos /= 2;
    while(pos >= 1){
        tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
        pos /= 2;
    }
}

void solve(){
    emp.a = emp.b = emp.c = emp.ab = emp.bc = emp.abc = 1e9;
    for(int i=0;i<roz;i++) tree[i] = emp;
    int n, q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        char s; cin >> s;
        upd(i, s);
    }
    while(q--){
        int pos; cin >> pos;
        char x; cin >> x;
        upd(pos, x);
        cout << tree[1].abc << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();

    return 0;
}