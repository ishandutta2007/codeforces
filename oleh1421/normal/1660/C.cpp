#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;
int last[N];
int dp[N];
void solve(){
    for (int i=0;i<26;i++) last[i]=0;
    string s;cin>>s;
    int n=s.size();
    s="."+s;
    dp[0]=0;
    for (int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if (last[s[i]-'a']){
            dp[i]=max(dp[i],dp[last[s[i]-'a']-1]+2);
        }
        last[s[i]-'a']=i;
    }
    cout<<n-dp[n]<<endl;


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}