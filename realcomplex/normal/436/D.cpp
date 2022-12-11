#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N= (int)2e5 + 9;

int cell[N];
int mon[N];
int sp[N];
int dp[N][2];
int L[N];
int R[N];

void upd(int &a, int b){
    a = max(a, b);
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        cin >> mon[i];
    }
    for(int i = 1; i <= m ; i ++ ){
        cin >> sp[i];
        cell[sp[i]] = 1;
    }
    sort(mon + 1, mon + 1 + n);
    sort(sp + 1, sp + 1 + m);
    for(int i = 1; i <= n; i ++ ){
        if(i == 1) L[i] = 0;
        else{
            if(mon[i] - mon[i - 1] == 1) L[i] = L[i-1];
            else L[i] = i-1;
        }
    }
    int points;
    int sz;
    for(int i = 1; i <= n; i ++ ){
        upd(dp[i][1], dp[L[i]][0]);
        
        points = 0 ;
        for(int j = m ; j >= 1; j -- ){
            if(mon[i] < sp[j]){
                continue;
            }
            points ++ ;
            sz = mon[i] - sp[j];
            if(i - sz <= 0)
                continue;
            upd(dp[i][1], dp[L[i-sz]][0] + points);
        }
        points = 0;
        upd(dp[i][0], dp[i-1][0]);
        upd(dp[i][0], dp[i-1][1]);
        upd(dp[i][0], dp[i][1]);
        for(int j = 1 ; j <= m; j ++ ){
            if(sp[j] <= mon[i])
                continue;
            points ++ ;
            sz = sp[j] - mon[i];
            if(i + sz > n)
                continue;
            upd(dp[i+sz][0],dp[i][1] + points);
        }
    }
    cout << dp[n][0];
    return 0;
}