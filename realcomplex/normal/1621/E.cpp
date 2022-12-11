#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;

int A[N];

struct Node{
    int low;
    int lazy;
};
vector<int> mk;
Node T[N * 4 + 512];
bool mark[N * 4 + 512];

void add(int nd){
    if(!mark[nd]){
        mark[nd]=true;
        mk.push_back(nd);
    }
}

void push(int node, int cl, int cr){
    T[node].low += T[node].lazy;
    add(node);
    if(cl != cr){
        add(node * 2);
        add(node * 2 + 1);
        T[node * 2].lazy += T[node].lazy;
        T[node * 2 + 1].lazy += T[node].lazy;
    }
    T[node].lazy = 0;
}

void upd(int node, int cl, int cr, int tl, int tr, int u){
    push(node, cl, cr);
    add(node);
    if(cr < tl || cl > tr) return;
    if(cl >= tl && cr <= tr){
        T[node].lazy = u;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    upd(node * 2, cl, mid, tl, tr, u);
    upd(node * 2 + 1, mid + 1, cr, tl, tr, u);
    T[node].low = min(T[node * 2].low, T[node * 2 + 1].low);
}


void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        upd(1, 1, N - 1, 1, A[i], +1);
    }
    vector<vector<int>> S;
    int k;
    int x;
    ll avg;
    for(int i = 1; i <= m; i ++ ){
        cin >> k;
        avg = 0;
        S.push_back({});
        for(int j = 1; j <= k ; j ++ ){
            cin >> x;
            avg += x;
            S.back().push_back(x);
        }
        avg = (avg + k - 1) / k;
        upd(1, 1, N - 1, 1, avg, -1);
    }
    ll nw;
    int sz;
    ll av;
    for(int i = 1; i <= m; i ++ ){
        avg = 0;
        for(auto x : S[i-1]){
            avg += x;
        }
        sz = S[i-1].size();
        av = (avg + sz - 1) / sz;
        for(auto x : S[i-1]){
            sz = (int)S[i-1].size() - 1;
            nw = avg - x;
            nw = (nw + sz - 1) / sz;
            upd(1, 1, N - 1, 1, av, +1);
            upd(1, 1, N - 1, 1, nw, -1);
            if(T[1].low >= 0) cout << 1;
            else cout << 0;
            upd(1, 1, N - 1, 1, nw, +1);
            upd(1, 1, N - 1, 1, av, -1);
        }
    }
    for(auto t : mk){
        mark[t]=false;
        T[t] = {0,0};
    }
    mk.clear();
    cout << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}