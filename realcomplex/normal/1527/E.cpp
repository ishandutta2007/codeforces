#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 35010;
const int M = (int)2e6 + 1;

struct persistent_tree{
    struct Node{
        ll sum;
        int lef;
        int rig;
    };
    Node T[M];
    int cnt;
    void init(){
        T[0] = {0ll, -1, -1};
        cnt = 1;
    }
    int update(int node, int cl, int cr, int id, ll v){
        if(node == -1){
            node = cnt;
            T[node] = {0ll, -1, -1};
            cnt ++ ;
        }
        else{
            int id = cnt;
            cnt ++ ;
            T[id] = T[node];
            node = id;
        }
        T[node].sum += v;
        if(cl == cr) return node;
        int mid = (cl + cr) / 2;
        if(mid >= id){
            int temp = update(T[node].lef, cl, mid, id, v);
            T[node].lef = temp;
        }
        else{
            int temp = update(T[node].rig, mid + 1, cr, id, v);
            T[node].rig = temp;
        }
        return node;
    }
    ll get(int node, int cl, int cr, int tl, int tr){
        if(node == -1) return 0ll;
        if(cr < tl || cl > tr) return 0;
        if(cl >= tl && cr <= tr){
            return T[node].sum;
        }
        int mid = (cl + cr) / 2;
        return get(T[node].lef, cl, mid, tl ,tr) + get(T[node].rig, mid + 1, cr, tl, tr);
    }

};

int A[N];
int pv[N];

int root1[N];
int root2[N];

persistent_tree f1, f2;
int n;

ll calc(int li, int ri){
    return f1.get(root1[ri], 1, n, li, ri) - f2.get(root2[li], 1, n, li, ri);
}

const ll inf = (ll)1e13;
ll dp[101][N];

vector<int> pos[N];
int sid[N];

void solve(int k, int li, int ri, int optl, int optr){
    if(li > ri) return;
    int mid = (li + ri) / 2;
    int opt = -1;
    ll low = inf;
    ll F;
    int sha = min(mid, optr);
    ll cur = calc(sha, mid);
    low = cur + dp[k - 1][sha - 1];
    opt = sha;
    for(int j = sha - 1; j >= optl; j -- ){
        if(sid[j] + 1 < pos[A[j]].size()){
            if(pos[A[j]][sid[j] + 1] <= mid)
                cur += pos[A[j]][sid[j] + 1] - j;
        }
        F = cur + dp[k - 1][j - 1];
        if(F <= low){
            low = F;
            opt = j;
        }
    }
    dp[k][mid] = low;
    solve(k, li, mid - 1, optl, opt);
    solve(k, mid + 1, ri, opt, optr);
}

int main(){
    fastIO;
    int k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        sid[i] = pos[A[i]].size();
        pos[A[i]].push_back(i);

    }
    for(int i = 1; i <= n; i ++ ){
        pv[i] = -1;
    }
    root1[0] = 0;
    f1.init();
    for(int i = 1; i <= n; i ++ ){
        root1[i] = root1[i - 1];
        if(pv[A[i]] != -1){
            root1[i] = f1.update(root1[i], 1, n, pv[A[i]], -pv[A[i]]);
        }
        root1[i] = f1.update(root1[i], 1, n, i, +i);
        pv[A[i]] = i;
    }
    for(int i = 1; i <= n; i ++ ){
        pv[i] = -1;
    }
    root2[n + 1] = 0;
    f2.init();
    for(int i = n; i >= 1; i -- ){
        root2[i] = root2[i + 1];
        if(pv[A[i]] != -1){
            root2[i] = f2.update(root2[i], 1, n, pv[A[i]], -pv[A[i]]);
        }
        root2[i] = f2.update(root2[i], 1, n, i, +i);
        pv[A[i]] = i;
    }

    dp[0][0]=0;
    for(int j = 0 ; j <= k ; j ++ ){
        for(int i = 1; i <= n; i ++ ){
            dp[j][i] = inf;
        }
    }
    for(int i = 1; i <= k ; i ++ ){
        solve(i, 1, n, 1, n);
    }
    cout << dp[k][n] << "\n";
    return 0;
}