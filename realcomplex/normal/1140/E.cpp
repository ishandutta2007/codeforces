#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)2e5 + 9; 
const ll MOD = 998244353;

ll k;

ll mult(ll a, ll b){
    return (a * b) % MOD;
}

void add(ll &a, ll b){
    a = (a + b) % MOD;
}

ll solve(int len, ll ff, ll ss){
    if(k == 2){
        if(ff==-1 && ss==-1)
            return 2;
        if(ff==-1 || ss==-1)
            return 1;
        ff -- ;
        ss -- ;
        ll r = ff ^ (len % 2);
        return r != ss;
    }
    ll dp[len][3];
    memset(dp, 0, sizeof dp);
    if(ff==-1) 
        dp[0][0] = 1, dp[0][1] = 1, dp[0][2] = k - 2;
    else
        dp[0][1] = 1, dp[0][2] = k - 2;
    for(int i = 1; i < len ; i ++ ){
        add(dp[i][0], dp[i-1][1]);
        add(dp[i][0], dp[i-1][2]);
        add(dp[i][1], dp[i-1][0]);
        add(dp[i][1], dp[i-1][2]);
        add(dp[i][2], mult(dp[i-1][0],k-2));
        add(dp[i][2], mult(dp[i-1][1],k-2));
        add(dp[i][2], mult(dp[i-1][2],k-3));
    }
    if(ss==-1)
        return dp[len-1][0] + dp[len-1][1] + dp[len-1][2];
    else if(ss == ff)
        return dp[len-1][1] + dp[len-1][2];
    else
        return dp[len-1][0] + dp[len-1][2];
}

ll Calc(vector<ll> nums){
    
    ll ff = -1;
    ll ss = -1;
    int cnt = 0;
    ll res = 1ll;
    for(auto x : nums){
        if(x == -1){
            cnt ++ ;
        }
        else{
            ss=x;
            if(cnt > 0)res = mult(res, solve(cnt,ff,ss));
            else{
                if(ss==ff){
                    res *= 0;
                }
            }
            ss=-1;
            ff=x;
            cnt=0;
        }
    }
    if(cnt > 0)
        res = mult(res, solve(cnt,ff,ss));
    return res;
}

int main(){
    fastIO;
    int n;
    cin >> n >> k;
    vector<ll> v1, v2;
    ll a;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> a;
        if(i % 2 == 0) v1.push_back(a);
        else v2.push_back(a);
    }
    cout << mult(Calc(v1),Calc(v2));
    return 0;
}