#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5010;
int tag[N];
int s[N];

ll dp[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> tag[i];
        dp[i]=0;
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> s[i];
    }
    ll f0, f1;
    ll cost;
    for(int i = 1; i <= n; i ++ ){
        for(int j = i - 1; j >= 1; j -- ){
            if(tag[i] == tag[j]) continue;
            f0 = dp[j];
            f1 = dp[i];
            cost = abs(s[i] - s[j]);
            if(dp[i] < f0 + cost){
                dp[i] = f0 + cost;
            }
            if(dp[j] < f1 + cost){
                dp[j] = f1 + cost;
            }
        }
    }
    ll outp = 0;
    for(int i = 1; i <= n; i ++ )
        outp = max(outp, dp[i]);
    cout << outp << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}