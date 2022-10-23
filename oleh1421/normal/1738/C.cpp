#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const int N=210;
const int TSZ=1e7;
const ll inf=1e18;
ll a[N];
ll s[N];
ll l[N],r[N];
int dp[N][N][2][2];
int f(int x,int y,int need,int tot){
    if (x==0 && y==0) return (need==0);
    if (dp[x][y][need][tot]!=-1) return dp[x][y][need][tot];
    int win=0;
    if (x) win|=(f(x-1,y,need^((y+1)%2),tot)^1);
    if (y) win|=(f(x,y-1,(need^1)^((y)%2),tot)^1);
    return dp[x][y][need][tot]=win;
}
void solve(){
    int n;cin>>n;
    int x=0,y=0;
    for (int i=1;i<=n;i++){
        int a;cin>>a;
        if (a%2) y++;
        else x++;
    }
    int tot=(y+1)%2;
    if (f(x,y,0,tot)) cout<<"Alice\n";
    else cout<<"Bob\n";


//    s[i]-s[i-1]>=s[i-1]-s[i-2]
//
//    s[i-2]>=s[i]-s[i-1]*2


}
int main() {
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            for (int t=0;t<4;t++){
                dp[i][j][t/2][t%2]=-1;
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}