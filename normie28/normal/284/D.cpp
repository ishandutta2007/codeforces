#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
typedef long long ll;
int a[M] , ans , n , cnt;
ll dp[2][M];
bool vis[2][M];
ll dfs(int pos , int flag) {
    if(pos <= 0 || pos > n) return 0;
    if(dp[flag][pos]) return dp[flag][pos];
    if(vis[flag][pos]) ans = 1;
    if(ans) return -1;
    vis[flag][pos] = true;
    ll sum = 0;
    if(flag == 1) {
        sum += (a[pos] + dfs(pos + a[pos] , 0));
    }
    else {
        sum += (a[pos] + dfs(pos - a[pos] , 1));
    }
    if(!ans)
        dp[flag][pos] = sum;
    return sum;
}
int main() {
	cin>>n;
    for(int i = 2 ; i <= n ; i++) {
        cin>>a[i];
    }
    ll gg;
    for(int i = 1 ; i < n ; i++) {
        ans = 0;
        gg = dfs(i + 1 , 0);
        if(ans) {
        	cout<<-1<<"\n";
        }
        else {
            cout<<gg + (ll)i<<"\n";
        }
    }
}