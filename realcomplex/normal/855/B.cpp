#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

const int MAXN = 1e5+5;
ll dp[MAXN][4];
ll arr[MAXN];
void ini(){
    for(int j = 0;j<MAXN;j++){
        dp[j][0] = LLONG_MIN;
        dp[j][1] = LLONG_MIN;
        dp[j][2] = LLONG_MIN;
    }
}

ll p,q,r;

void fil(){
    for(int i = 1;i<MAXN;i++)dp[i][0] = max(dp[i-1][0],p*arr[i]);
    for(int i = 1;i<MAXN;i++)dp[i][1] = max(dp[i-1][1],dp[i][0]+(q*arr[i]));
    for(int i = 1;i<MAXN;i++)dp[i][2] = max(dp[i-1][2],dp[i][1]+(r*arr[i]));
}

main(){
    //open();
    ini();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n >> p >> q >> r;
    for(int j = 1;j<=n;j++) cin >> arr[j];
    fil();
    cout << dp[n][2];
    return 0;
}