//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <algorithm>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=11;
vector<int>g[N][52];
string s[N];
int dp[52][(1<<N)];
pair<int,int> pr[52][(1<<N)];
int get_char(int ind){
    if (ind<26) return char(ind+'a');
    return char(ind-26+'A');
}
int get_int(char c){
    if (c>='a' && c<='z') return c-'a';
    return (c-'A')+26;
}
void solve(){
    int n;cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<52;j++){
            g[i][j].clear();
        }
    }
    for (int i=0;i<n;i++) cin>>s[i];
    for (int i=0;i<n;i++){
        for (int j=0;j<s[i].size();j++){
            g[i][get_int(s[i][j])].push_back(j);
        }
    }
    vector<pair<vector<int>,pair<int,int> > >v;
    for (int c=0;c<52;c++){

        for (int mask=0;mask<(1<<n);mask++){
            vector<int>u;
            bool bad=false;
            for (int i=0;i<n;i++){
                if (g[i][c].empty()) {
                    bad=true;
                    break;
                }
                if (mask&(1<<i)){
                    if (g[i][c].size()==1){
                        bad=true;
                        break;
                    }
                    u.push_back(g[i][c][1]);
                } else {
                    u.push_back(g[i][c][0]);
                }
            }
            if (!bad) v.push_back({u,{mask,c}});
        }
    }
    for (int c=0;c<52;c++){
        for (int mask=0;mask<(1<<n);mask++) {
            dp[c][mask]=0;
            pr[c][mask]={-1,-1};
        }
    }
    sort(v.begin(),v.end());
    for (auto cur:v){
        int mask=cur.second.first;
        int c=cur.second.second;
//        cout<<c<<endl;
        dp[c][mask]=1;
        pr[c][mask]={-1,-1};
        for (int i=0;i<n;i++){
            if (mask&(1<<i)){
                if (dp[c][mask]<dp[c][mask^(1<<i)]) {
                    dp[c][mask]=dp[c][mask^(1<<i)];
                    pr[c][mask]=pr[c][mask^(1<<i)];
                }
            }
        }
        for (int c1=0;c1<52;c1++){
            int mask1=0;
            bool ok=true;
            for (int i=0;i<n;i++){
                if (g[i][c1].empty() || g[i][c1][0]>=cur.first[i]) ok=false;
                else if (g[i][c1].size()==1 || g[i][c1][1]>=cur.first[i]) mask1=mask1;
                else mask1^=(1<<i);
            }
            if (ok){
                if (dp[c1][mask1]+1>dp[c][mask]){
                    dp[c][mask]=dp[c1][mask1]+1;
                    pr[c][mask]={c1,mask1};
                }
            }
        }
    }
    int c=0,mask=0;
    for (int i=0;i<52;i++){
        for (int j=0;j<(1<<n);j++){
            if (dp[i][j]>dp[c][mask]){
                c=i;
                mask=j;
            }
        }
    }
    cout<<dp[c][mask]<<endl;
    if (dp[c][mask]==0) return;
    string ans="";
    while (c!=-1){
        ans+=get_char(c);
        int nw_c=pr[c][mask].first;
        int nw_mask=pr[c][mask].second;
        c=nw_c;
        mask=nw_mask;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;




}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }




    return 0;
}
/**
100000000 3
0 0 0 1 1
**/