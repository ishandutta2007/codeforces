#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5;
const int K = 60;
int a[N];
int n;
int res = 1;

unordered_map<int, int> dp[N];

void solve(){
    for(int d = 0; d <= K; d ++ ){
        unordered_map<int, int> st;
        for(int i = 0 ; i < n ; i ++ ){
            st[a[i] - i * d] ++ ;
            res = max(res, st[a[i] - i * d]);
        }
    }
    int diff;
    for(int i = 0 ; i < n; i ++ ){
        dp[i].clear();
        for(int j = i - 1; j >= 0 ; j -- ){
            if(i - j > N/K) break;
            if(a[i] - a[j] <= 0) continue;
            diff = (a[i] - a[j]) / (i - j);
            if((a[i] - a[j]) % (i - j) != 0) continue;
            if(diff < K) continue;
            //cout << i << " " << j << "| " << diff << "\n";
            if(dp[j].count(diff)) dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
            else dp[i][diff] = max(dp[i][diff], 2);
            res = max(res, dp[i][diff]);
        }
    }

}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    solve();
    reverse(a, a + n);
    solve();
    cout << n-res << "\n";
    return 0;
}