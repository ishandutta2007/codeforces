#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;

void solve(){
    int n;
    cin >> n;
    vector<int> q(n * 2);
    for(int i = 0 ; i < n * 2; i ++ ){
        cin >> q[i];
    }
    int mx = 0;
    vector<int> ids;
    for(int i = 0 ;i < n * 2; i ++ ){
        mx = max(mx, q[i]);
        if(mx == q[i]){
            ids.push_back(i);
        }
    }
    ids.push_back(n*2);
    vector<int> sz;
    for(int i = 1; i < ids.size(); i ++ ){
        sz.push_back(ids[i]-ids[i-1]);
    }
    vector<bool> dp(n * 2 + 1);
    for(int i = 0 ; i <= n * 2; i ++ ){
        dp[i]=false;
    }
    dp[0]=true;
    for(auto x : sz){
        for(int j = n * 2; j >= x ; j -- ){
            if(dp[j-x]){
                dp[j]=true;
            }
        }
    }
    if(dp[n]) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}