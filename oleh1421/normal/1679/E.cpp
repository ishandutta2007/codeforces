//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
#define int ll
const int N=500105;
const ll inf=2e18;
const ll mod=998244353;
int ans[(1<<17)];
ll dp[18][(1<<17)];
ll pw[N];
void solve(int Case){
    int n;cin>>n;
    string s;cin>>s;
    for (int cn=0;cn<=17;cn++){
        pw[0]=1;
        for (int i=1;i<=n;i++){
            pw[i]=(pw[i-1]*cn)%mod;
        }
        for (int mid=0;mid<n;mid++){
            int mask=0;
            int mult=0;
            for (int i=0;i<n;i++) mult+=(s[i]=='?');
            for (int l=mid,r=mid;0<=l && r<n;l--,r++){
                if (s[l]=='?' && s[r]=='?') mult-=(l!=r);
                else if (s[l]=='?') mask|=(1<<(s[r]-'a')),mult--;
                else if (s[r]=='?') mask|=(1<<(s[l]-'a')),mult--;
                else if (s[l]!=s[r]) break;
//                if (cn==2) {
//                    cout<<l<<" "<<r<<" "<<mask<<" "<<mult<<endl;
//                    sum+=mult;
//                }
                dp[cn][mask]+=pw[mult];
                dp[cn][mask]%=mod;
            }
        }
        for (int mid=0;mid<n-1;mid++){
            int mask=0;
            int mult=0;
            for (int i=0;i<n;i++) mult+=(s[i]=='?');
            for (int l=mid,r=mid+1;0<=l && r<n;l--,r++){
                if (s[l]=='?' && s[r]=='?') mult--;
                else if (s[l]=='?') mask|=(1<<(s[r]-'a')),mult--;
                else if (s[r]=='?') mask|=(1<<(s[l]-'a')),mult--;
                else if (s[l]!=s[r]) break;
//                if (cn==2) {
//                    cout<<l<<" "<<r<<" "<<mask<<" "<<mult<<endl;
//                    sum+=mult;
//                }
                dp[cn][mask]+=pw[mult];
                dp[cn][mask]%=mod;
            }
        }
    }
    for (int cn=0;cn<=17;cn++){
        for (int i=0;i<17;i++){
            for (int mask=0;mask<(1<<17);mask++){
                if (mask&(1<<i)){
                    dp[cn][mask]+=dp[cn][mask^(1<<i)];
                    dp[cn][mask]%=mod;
                }
            }
        }
    }
    int q;cin>>q;
    for (int it=1;it<=q;it++){
        string s;cin>>s;
        int mask=0;
        for (auto i:s){
            mask|=(1<<(i-'a'));
        }
        cout<<dp[__builtin_popcount(mask)][mask]<<endl;
    }



}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**

**/