#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 10;
const ll inf = (ll)1e18;
ll P[3][N];
ll A[N];
ll B[N];

vector<pii> segs[N];

struct Node{
    ll ma;
    ll mb;
    ll soln;
};

Node T[N * 4 + 512];

Node unite(Node A, Node B){
    Node res;
    res.ma = max(A.ma, B.ma);
    res.mb = max(A.mb, B.mb);
    res.soln = max(A.soln, B.soln);
    res.soln = max(res.soln, A.ma + B.mb);
    return res;
}

void reset(int node, int cl, int cr){
    T[node] = {-inf, -inf, -inf};
    if(cl == cr) return;
    int mid = (cl + cr) / 2;
    reset(node * 2, cl, mid);
    reset(node * 2 + 1, mid + 1, cr);
}


void sett(int node, int cl, int cr, int id, Node init){
    if(cl == cr){
        T[node] = init;
        return;
    }
    int mid = (cl + cr) / 2;
    if(mid >= id)
        sett(node * 2, cl, mid, id, init);
    else
        sett(node * 2 + 1, mid + 1, cr, id, init);
    T[node] = unite(T[node * 2], T[node * 2 + 1]);
}

Node get(int node, int cl, int cr, int tl, int tr){
    if(cr < tl || cl > tr) return {-inf, -inf, -inf};
    if(cl >= tl && cr <= tr){
        return T[node];
    }
    int mid = (cl + cr) / 2;
    Node A = get(node * 2, cl, mid, tl, tr);
    Node B = get(node * 2 + 1, mid + 1, cr, tl, tr);
    return unite(A, B);
}

ll dp[N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n, q;
    cin >> n >> q;
    for(int i = 0 ; i < 3; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            cin >> P[i][j];
            P[i][j] += P[i][j-1];
        }
    }
    for(int i = 1; i <= n; i ++ ){
        A[i] = P[0][i] - P[1][i-1];
        B[i] = P[2][n] - P[2][i - 1] + P[1][i];
    }
    int li, ri, ki;
    for(int i = 1; i <= q; i ++ ){
        cin >> li >> ri >> ki;
        segs[li].push_back(mp(ri, ki));
    }
    ll res = -inf;
    Node chk;
    for(int i = n ;i >= 1; i -- ){
        dp[i]=-inf;
        sett(1, 1, n, i, {-inf, B[i], -inf});
        for(auto x : segs[i]){
            chk = get(1, 1, n, i, x.fi);
            dp[i] = max(dp[i], chk.mb - x.se);
            chk = get(1, 1, n, i + 1, x.fi + 1);
            dp[i] = max(dp[i], chk.ma - x.se);
        }
        sett(1, 1, n, i, {dp[i], B[i], -inf});
    }
    for(int i = 1; i <= n; i ++ ){
        sett(1, 1, n, i, {A[i], dp[i], -inf});
    }
    for(int i = 1; i <= n; i ++ ){
        for(auto x : segs[i]){
            chk = get(1, 1, n, i, x.fi + 1);
            res = max(res, chk.soln - x.se);
        }
    }

    for(int i = 1; i <= n; i ++ ){
        sett(1, 1, n, i, {A[i], B[i], A[i] + B[i]});
    }
    for(int i = 1; i <= n; i ++ ){
        for(auto x : segs[i]){
            chk = get(1, 1, n, i, x.fi);
            res = max(res, chk.soln - x.se);
        }
    }
    cout << res << "\n";
    return 0;
}