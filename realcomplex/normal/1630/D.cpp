#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void maxi(ll &v, ll y){
    v = max(v, y);
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
        }
        int g;
        cin >> g;
        int x;
        for(int i = 2; i <= m ; i ++ ){
            cin >> x;
            g = __gcd(g, x);
        }
        ll dp[g][2];
        ll n0, n1;
        ll s0 = 0;
        ll s1 = 0;
        for(int mod = 0 ; mod < g; mod ++ ){
            dp[mod][0] = 0;
            dp[mod][1] = -(ll)1e18;
            for(int id = mod; id < n; id += g){
                n0 = dp[mod][0] + a[id];
                n1 = dp[mod][1] + a[id];
                maxi(n1, dp[mod][0] - a[id]);
                maxi(n0, dp[mod][1] - a[id]);
                dp[mod][0] = n0;
                dp[mod][1] = n1;
            }
            s0 += dp[mod][0];
            s1 += dp[mod][1];
        }
        cout << max(s0, s1) << "\n";
    }
    return 0;
}