#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 65540;

struct Node{
    int value;
    int lazy;
};

struct Tree{
    Node T[N * 2];

    void push(int node, int cl, int cr){
        T[node].value += T[node].lazy;
        if(cl != cr){
            T[node * 2].lazy += T[node].lazy;
            T[node * 2 + 1].lazy += T[node].lazy;
        }
        T[node].lazy = 0;
    }

    void update(int node, int cl, int cr ,int tl, int tr, int vl){
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
        T[node].value = max(T[node * 2].value, T[node * 2 + 1].value);
    }

    int query(int node, int cl, int cr, int tl, int tr){
        push(node, cl, cr);
        if(cr < tl)
            return 0;
        if(cl > tr)
            return 0;
        if(cl >= tl && cr <= tr){
            return T[node].value;
        }
        int mid = (cl + cr) / 2;
        return query(node * 2, cl ,mid, tl, tr) + query(node * 2 + 1, mid + 1, cr, tl, tr);
    }
    void Init(){
        for (int i = 0 ; i < N * 2; i ++ )
            T[i] = {0, 0};
    }
};


const int K = 51;
Tree Y[K];

int las[N];

int dp[N][K];

int main(){
    fastIO;
    for(int i= 0 ; i < N;i ++ )las[i] = -1;
    int n, k;
    cin >> n >> k;
    for(int j = 0 ; j <= k ; j ++ )
        Y[j].Init();
    int x;
    int m = n + 1;
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        for(int j = 0 ; j <= k ; j ++ ){
            Y[j].update(1, 0, m - 1, las[x] + 1, i, +1);
        }
        for(int j = 0;j  <= k ; j ++ ){
            Y[j].update(1, 0, m - 1, i, i, dp[i-1][j]);
        }
        for(int j = 1; j <= k ; j ++ ){
            dp[i][j] = Y[j - 1].T[1].value;
        }

        las[x] = i;
    }
    cout << dp[n][k] << "\n";
    return 0;
}