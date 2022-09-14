#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
bool used[2000001];
int dp[2000001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //string s;cin>>s;
    string s;
    cin>>s;
/*
    for (int i=0;i<1000000;i++) s+=char(i%20+int('a'));
    //cout<<s;
    random_shuffle(s.begin(),s.end());
*/
    int n=(int)s.size();
    int xr=0;
    for (int i=0;i<=19;i++) xr^=(1<<i);
    vector<int>masks;
    for (int i=0;i<n;i++){
        int cur_mask=0;
        int j=i;
        while (j<n && ((1<<(s[j]-'a'))&cur_mask)==0){
              cur_mask|=(1<<(s[j]-'a'));
              if (!used[cur_mask]){
                used[cur_mask]=true;
                masks.push_back(cur_mask);
              }
              j++;
        }
    }
    for (auto i:masks) dp[i]=__builtin_popcount(i);
    for (int i=1;i<(1<<20);i++){
        for (int j=0;j<20;j++){
            if (i&(1<<j)) continue;
            dp[i^(1<<j)]=max(dp[i^(1<<j)],dp[i]);
        }
    }
    int res=0;
    for (auto mask:masks){
        res=max(res,__builtin_popcount(mask)+dp[mask^xr]);
    }
    cout<<res;
    return 0;
}