#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int long long
ll dp[1000001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    ll res=0ll;
    for (int i=0;i<n;i++){
        int l=i;
        while (l>0 && s[l-1]!=s[i]) l--;
        int r=i;
        while (r+1<n && s[r+1]!=s[i]) r++;
        res+=(i-l)+(r-i)+1;
        if (i+1<n && s[i]!=s[i+1]) res--;
    }
    int cnt=0;
    for (int i=0;i<n;i++){
        int cntA=0;
        int cntB=0;
        for (int j=i;j<n;j++){

        }
    }
    cout<<n*(n+1ll)/2ll-res;

}
///AAABABB