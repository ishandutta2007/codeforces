#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const int N = (int)1e5;
int dp[N];

struct Neg{ 
    int total;
    int req;
    int ch;
    bool operator<(const Neg T){
        if(total == T.total)
            return req > T.req;
        else
            return total > T.total; 
    }
};

int main(){
    fastIO;
    int n, cur;
    cin >> n >> cur;
    vector<pii> pp;
    vector<Neg> vv;
    int a, b;
    for(int i = 0 ; i < n; i ++ ){
        cin >> a >> b;
        if(b>=0)pp.push_back(mp(a, b));
        else
            vv.push_back({a+b, a, b});
    }
    sort(pp.begin(), pp.end());
    int res = 0;
    for(int i = 0;i < pp.size(); i ++ ){
        if(pp[i].fi <= cur){
            cur += pp[i].se;
            res ++ ;
        }
    }
    for(int i = 0 ; i < N ; i ++ )
        dp[i] = -(int)1e9;
    sort(vv.begin(), vv.end());
    dp[cur] = res;
    for(int i = 0 ; i < vv.size();i ++ ){
        for(int j = vv[i].req ; j < N ; j ++ ){
            if(j + vv[i].ch >= 0)dp[j + vv[i].ch] = max(dp[j + vv[i].ch], dp[j] + 1);
        }
    }
    for(int i = 0; i < N ; i ++ )
        res = max(res, dp[i]);
    cout << res << "\n";
    return 0;
}