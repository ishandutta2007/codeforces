#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int Lg=20;
const ll mod=998244353;
const ll inv2=(mod+1)/2;
ll n;
map<ll,int>mp;
int F(ll x){
    if (mp.find(x)!=mp.end()) return mp[x];
    int cnt=0;
    int mask=0;
    ll cur=x;
    while (cur){
        mask|=(1<<(cur%10));
        cur/=10;
        cnt++;
    }
    if (cnt==n) return 0;
    int res=101;
    for (int i=2;i<=9;i++){
        if (mask&(1<<i)){
            res=min(res,1+F(x*i));
        }
    }
    return mp[x]=res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x;cin>>n>>x;
    ll res=F(x);
    if (res>100) res=-1;
    cout<<res<<endl;

    return 0;
}
/*
3
1 5
2 6
3 4
*/