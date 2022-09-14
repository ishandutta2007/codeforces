#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int long long
ll cnt[31][31];
int n,m;
ll dp[2000001];
bool used[2000001];
ll F(int mask){
    if (mask+1==(1<<m)) return 0;
    if (used[mask]) return dp[mask];
    ll res=10000001;
    ll cn=__builtin_popcount(mask);
    for (int i=0;i<m;i++){
        ll cur=0;
        if (mask&(1<<i)) continue;
        for (int j=0;j<m;j++){
            if (j==i) continue;
            if (mask&(1<<j)) cur+=cn*cnt[i][j];
            else cur-=cn*cnt[i][j];
        }
        cur+=F(mask^(1<<i));
        res=min(res,cur);
    }
    used[mask]=true;
    return dp[mask]=res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    string s;cin>>s;
    for (int i=0;i+1<n;i++){
        cnt[s[i]-'a'][s[i+1]-'a']++;
        cnt[s[i+1]-'a'][s[i]-'a']++;
    }
    cout<<F(0);

}