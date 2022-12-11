#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int N = (int)1e5 + 10;
map<int, int> idx;
int dp[N];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        int a;
        int xr = 0;
        for(int i = 0; i <= n; i ++ ){
            dp[i]=i;
        }
        idx.clear();
        idx[0]=0;
        for(int i = 1; i <= n; i ++ ){
            cin >> a;
            xr ^= a;
            dp[i]=dp[i-1]+1;
            if(idx.count(xr)){
                dp[i]=min(dp[i],dp[idx[xr]] + (i - idx[xr] - 1));
            }
            idx[xr] = i;
        }
        cout << dp[n] << "\n";
    }
    return 0;
}