#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 3;

ll dp[2][N];
int bit = 1;
int Cl=1, Cr=0;
int cnt[N];
int A[N];
ll answ = 0;

void go(int l, int r){
    while(Cl < l){
        cnt[A[Cl]] -- ;
        answ -= cnt[A[Cl]];
        Cl ++ ;
    }
    while(Cr < r){
        Cr ++ ;
        answ += cnt[A[Cr]];
        cnt[A[Cr]] ++ ;
    }
    while(Cl > l){
        Cl -- ;
        answ += cnt[A[Cl]];
        cnt[A[Cl]] ++ ;
    }
    while(Cr > r){
        cnt[A[Cr]] -- ;
        answ -= cnt[A[Cr]];
        Cr -- ;
    }
}

void solve(int l, int r, int optl, int optr){
    if(l > r)
        return;
    int mid = (l + r) / 2;
    ll best = (ll)1e13;
    int id = -1;
    for(int j = optl; j <= min(optr, mid -1); j ++ ){
        go(j+1,mid);
        if(dp[!bit][j] + answ < best){
            best = dp[!bit][j] + answ;
            id = j;
        }
    }
    dp[bit][mid] = best;
    solve(l,mid-1,optl,id);
    solve(mid+1,r,id,optr);
}

int main(){
    fastIO;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    for(int t = 1; t <= n; t ++ )
        dp[0][t] = (ll)1e13;

    for(int p = 0; p < k ; p ++ ){
        solve(1, n, 0, n-1);
        bit ^= 1;
    }
    cout << dp[!bit][n];
    return 0;
}