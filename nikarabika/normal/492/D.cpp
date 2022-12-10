#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 2e6 + 10;
int dp[maxn];
ll t;
ll x, y;

void filldp(int q){
    if(dp[q - 1] == 0)
        filldp(q - 1);
    if(dp[q] == 0)
        if(x - (t % x) < y - (t % y)){
            t += x - (t % x);
            dp[q] = 1;
        }
        else if(x - (t % x) > y - (t % y)){
            t += y - (t % y);
            dp[q] = 3;
        }
        else{
            t += y - (t % y);
            dp[q] = 2;
            dp[q + 1] = 2;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n >> x >> y;
    dp[0] = 2;
    string s[4] = {"", "Vova", "Both", "Vanya"};
    rep(ali, n){
        ll a;
        cin >> a;
        a %= x + y;
        if(dp[a] == 0)
            filldp(a);
        cout << s[dp[a]] << endl;
    }
    return 0;
}