#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=500010;
const int T_SZ=3000010;
const ll mod=1000000007;
ll dp[20][2][2];
void solve(){
    int n;cin>>n;
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for (int i=0;i<10;i++){
        int d=n%10;
        n/=10;
        for (int x=0;x<2;x++){
            for (int y=0;y<2;y++){
//                cout<<i<<" "<<x<<" "<<y<<" "<<dp[i][x][y]<<endl;
                for (int a=0;a<10;a++){
                    int b=(d-a-x+10)%10;
//                    cout<<a<<" "<<b<<endl;
                    dp[i+1][y][((a+b+x)>=10)]+=dp[i][x][y];
                }
            }
        }
//        for
    }
    cout<<dp[10][0][0]-2ll<<endl;


}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

//0 2
//-1 3
//1 3
//0 4
/*
8
1 104
220 909
380 378
521 641
765 184
802 969
897 729
992 887

C - centroid

5
0 0 -1 -1 1
*/