//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define checkmin(a,b) if (a>b) a=b;
#define checkmax(a,b) if (a<b) a=b;
typedef long long ll;
using namespace std;
int mod=998244353ll;
int cnt[1001];
ll f1(ll a,int num){
    vector<ll>v;
    while (a){
        v.push_back(a%10ll);
        a/=10ll;
    }
    ll res=0ll;
    ll cur=1ll;
    int to=min(num,(int)v.size());
    for (int i=0;i<to;i++){
        res+=v[i]*cur*1ll;
       // res%=mod;
        cur*=100ll;
        cur%=mod;
    }
    for (int i=to;i<v.size();i++){
        res+=v[i]*cur;
        //res%=mod;
        cur*=10ll;
        cur%=mod;
    }
    res%=mod;
    return res;
}
ll f2(ll a,int num){
    vector<ll>v;
    while (a){
        v.push_back(a%10ll);
        a/=10ll;
    }
    ll res=0ll;
    ll cur=10ll;
    int to=min(num-1,(int)v.size());
    for (int i=0;i<to;i++){
        res+=v[i]*cur*1ll;
        //res%=mod;
        cur*=100ll;
        cur%=mod;
    }
    for (int i=to;i<v.size();i++){
        res+=v[i]*cur;
        //res%=mod;
        cur*=10ll;
        cur%=mod;
    }
    res%=mod;
    return res;
}

ll a[100001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        ll x=a[i];
        int cur=0;
        while (x){
            x/=10;
            cur++;
        }
        cnt[cur]++;
    }
    ll sum=0ll;
    for (int i=1;i<=n;i++){
         for (int j=1;j<=10;j++){
             sum+=(f1(a[i]*1ll,j)+f2(a[i]*1ll,j))*cnt[j];
             sum%=mod;
         }
    }
    cout<<sum;
    return 0;
}