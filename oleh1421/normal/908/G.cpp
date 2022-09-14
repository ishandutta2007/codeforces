#include <bits/stdc++.h>
#define endl '\n'
const long long mod=1000000007ll;
typedef long long ll;
using namespace std;
mt19937_64 rng(time(NULL));
const int c=9;
ll dp[710][710][2][2];
ll pow10[30001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    vector<int>v;
    while (!s.empty()){
        v.push_back(s.back()-'0');
        s.pop_back();
    }
    int sz=v.size();
    pow10[0]=1ll;
    for (int i=1;i<=sz;i++) pow10[i]=(pow10[i-1]*10ll)%mod;
    ll res=0ll;
    for (ll c=0;c<10;c++){
        for (int i=0;i<=sz;i++) for (int j=0;j<=sz;j++) for (int t=0;t<2;t++) for (int k=0;k<2;k++) dp[i][j][t][k]=0;
        dp[0][0][0][0]=1;
        for (int i=0;i<sz;i++){
            for (int j=0;j<sz;j++){
                for (int k=0;k<2;k++){
                    for (int z=0;z<10;z++){
                        ///t == 1
                        int i1=i+1;
                        int j1=j;
                        j1+=(z>c);
                        int k1=-1;
                        if (z>v[i]) k1=1;
                        else if (z<v[i]) k1=0;
                        else k1=k;
                        dp[i1][j1][1][k1]+=dp[i][j][1][k];
                        dp[i1][j1][1][k1]%=mod;
                        if (z==c){
                            dp[i1][j1][1][k1]+=dp[i][j][0][k];
                            dp[i1][j1][1][k1]%=mod;
                        }
                        ///t == 0
                        if (z==c) j1++;
                        dp[i1][j1][0][k1]+=dp[i][j][0][k];
                        dp[i1][j1][0][k1]%=mod;
                    }
                }
            }
        }
        //cout<<c<<endl;
        for (int i=0;i<=sz;i++){
            res+=(c*dp[sz][i][1][0]*pow10[i])%mod;
            res%=mod;
        }
    }
    cout<<res;
    return 0;
}