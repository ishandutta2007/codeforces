#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=510;
const ll mod=1000000007;
int p[N];
int used[N][N];
void dfs(int x,int y,int depth,int need){
    used[x][y]=need;
    if (depth==need) return;
    if (y-1<1 || used[x][y-1]) dfs(x+1,y,depth+1,need);
    else dfs(x,y-1,depth+1,need);
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=n;i++){
        dfs(i,i,1,p[i]);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++) cout<<used[i][j]<<" ";
        cout<<endl;
    }
}
int32_t main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5 9 7
...##....
..#.##..#
..#....##
.##...#..
....#....
W
**/

/**
3 2 3
3 3
2 2
1 1
**/