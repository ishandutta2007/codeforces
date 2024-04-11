//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define checkmin(a,b) if (a>b) a=b;
#define checkmax(a,b) if (a<b) a=b;
typedef long long ll;
using namespace std;
int mod=998244353ll;
int f(int a){
    vector<int>v;
    while (a){
        v.push_back(a%10ll);
        a/=10ll;
    }
    ll res=0ll;
    ll cur=1ll;
    for (int i:v){
        res+=11ll*cur*i;
        res%=mod;
        cur*=100ll;
        cur%=mod;
    }
    return res;
}
int a[100001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        sum+=f(a[i]);
        sum%=mod;
    }
    sum*=n*1ll;
    sum%=mod;
    cout<<sum;
    return 0;
}