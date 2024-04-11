//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
using namespace std;
const int N=2000010;
const ll mod=1000000007ll;
ll dp[N][2];
ll get(int i){
    if (i%3==2) return dp[i][0];
    else return dp[i][1];
}
void solve(){
    int n;cin>>n;
    cout<<get(n)<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp[1][0]=0;
    dp[1][1]=0;
    dp[2][0]=0;
    dp[2][1]=0;
    for (int i=3;i<N;i++){
        dp[i][0]=(get(i-1)+get(i-2)*2ll)%mod;
        dp[i][1]=(dp[i-1][0]+dp[i-2][0]*2ll+4ll)%mod;
    }
//    int n;cin>>n;
//    for (int i=1;i<=n;i++){
//        cout<<i%3<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
//    }
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
5 9 7
...##....
..#.##..#
..#....##
.##...#..
....#....
???????
*/