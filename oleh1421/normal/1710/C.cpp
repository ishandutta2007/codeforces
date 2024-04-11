//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define y1 y_1
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;
#define endl '\n'
//#define int ll
const int N=400010;
const ll mod=998244353;
const ll inf=1e18;
int dp[N][2][2][2][2][2][2];
void solve(){
    string s;cin>>s;
    reverse(s.begin(),s.end());
    dp[0][0][0][0][0][0][0]=1;
    for (int i=0;i<s.size();i++){
        int d=(s[i]-'0');
        for (int a=0;a<2;a++){
            for (int b=0;b<2;b++){
                for (int c=0;c<2;c++){
                    for (int ab=0;ab<2;ab++){
                        for (int ac=0;ac<2;ac++){
                            for (int bc=0;bc<2;bc++){
                                for (int da=0;da<2;da++){
                                    for (int db=0;db<2;db++){
                                        for (int dc=0;dc<2;dc++){
                                            int na=a;
                                            int nb=b;
                                            int nc=c;
                                            int nab=ab;
                                            int nac=ac;
                                            int nbc=bc;
                                            if (da<d) na=0;
                                            else if (da>d) na=1;
                                            if (db<d) nb=0;
                                            else if (db>d) nb=1;
                                            if (dc<d) nc=0;
                                            else if (dc>d) nc=1;
                                            if ((da^db)<(da^dc)+(db^dc)) nab=1;
                                            if ((da^dc)<(da^db)+(db^dc)) nac=1;
                                            if ((db^dc)<(da^dc)+(da^db)) nbc=1;
                                            dp[i+1][na][nb][nc][nab][nac][nbc]+=dp[i][a][b][c][ab][ac][bc];
                                            if (dp[i+1][na][nb][nc][nab][nac][nbc]>=mod) dp[i+1][na][nb][nc][nab][nac][nbc]-=mod;
                                        }
                                    }
                                }
                                }
                        }
                    }
                }
            }
        }
    }
    cout<<dp[s.size()][0][0][0][1][1][1]<<'\n';

}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
//    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}
/*
298375248
531556171


62875547
175951751
264083156
365049318
491406845

*/