#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
pair<int,int> a[300001];
int dp[300001];
int cnt[300001];
ll mod=1000000007ll;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].second>>a[i].first;
    sort(a+1,a+n+1);
    dp[n+1]=100000000000001ll;
    for (int i=n;i>0;i--){
        int ind=lower_bound(a+1,a+n+1,(pair<int,int>){a[i].second,-1ll})-a;
        if (ind==n+1){
            dp[i]=a[i].first;
            cnt[i]=1;
        } else {
             dp[i]=dp[ind]+a[i].first-a[i].second;
             cnt[i]=cnt[ind];
        }
        if (dp[i]>dp[i+1]){
            dp[i]=dp[i+1];
            cnt[i]=cnt[i+1];
        } else if (dp[i]==dp[i+1]){
            cnt[i]=(cnt[i]+cnt[i+1])%mod;
        }
    }
    cout<<cnt[1];
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/
//C:\Users\Zver\Desktop\666\main.cpp|22|error: invalid conversion from 'std::pair<long long int, long long int>*' to 'long long int' [-fpermissive]|