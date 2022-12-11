#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

const int N = 1e5 + 5;
int cnt[N];

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    int sk[n];
    int dp[n+1];
    dp[n] = 0;
    for(int i = 0;i<n;i++){
        cin >> sk[i];
        dp[i] = 0;
    }
    for(int j = n-1;j>=0;j--){
        dp[j] = dp[j+1];
        if(cnt[sk[j]] == 0){
            dp[j]++;
        }
        cnt[sk[j]]++;
    }
    //cout << "\n";
    int ask;
    for(int i = 0;i<m;i++){
        cin >> ask;
        cout << dp[ask-1] << "\n";
    }
    return 0;
}