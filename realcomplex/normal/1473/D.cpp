#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;

struct Node{
    int low;
    int high;
};

int pf[N];

Node T[N * 4 + 512];

void build(int node, int cl, int cr){
    if(cl == cr){
        T[node].low = pf[cl];
        T[node].high = pf[cl];
        return;
    }
    int mid = (cl + cr) / 2;
    build(node * 2, cl, mid);
    build(node * 2 + 1, mid + 1, cr);
    T[node].low = min(T[node*2].low,T[node*2+1].low);
    T[node].high = max(T[node*2].high,T[node*2+1].high);
}

Node get(int node, int cl, int cr, int tl, int tr){
    if(cr < tl || cl > tr)
        return {(int)1e9,-(int)1e9};
    if(cl >= tl && cr <= tr){
        return T[node];
    }
    int mid = (cl + cr) / 2;
    Node lf = get(node * 2, cl, mid, tl, tr);
    Node rf = get(node * 2 + 1, mid + 1, cr, tl, tr);
    return {min(lf.low,rf.low),max(lf.high,rf.high)};
}

void solve(){
    int n, m;
    cin >> n >> m;
    pf[0]=1;
    char q;
    for(int i = 1; i <= n; i ++ ){
        cin >> q;
        if(q == '+') pf[i] = pf[i - 1] + 1;
        else pf[i] = pf[i - 1] - 1;
    }
    pf[n+1]=pf[n];
    build(1,0,n+1);
    int li, ri;
    Node gl, gr;
    int com;
    for(int i = 1; i <= m ; i ++ ){
        cin >> li >> ri;
        gl = get(1, 0, n+1, 0, li - 1);
        gr = get(1, 0, n+1, ri + 1, n);
        com = pf[ri]-pf[li-1];
        gr.high-=com;
        gr.low-=com;
        cout << max(gr.high,gl.high)-min(gr.low,gl.low)+1 << "\n";

    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}