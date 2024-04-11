#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const ll mod=998244353;
const int N=1010;
ll fnd(ll x){
    for (ll i=2;i*i<=x;i++){
        if (x%i==0){
            return i;
        }
    }
    return 0;
}
void solve(){
    ll x,d;cin>>x>>d;
    int cnt=0;
    while (x%d==0){
        cnt++;
        x/=d;
    }
    if (cnt==1){
        cout<<"NO\n";
        return;
    }
    if (fnd(x)){
        cout<<"YES\n";
        return;
    }
    if (cnt==2){
        cout<<"NO\n";
        return;
    }
    x*=d;
    cnt--;
    ll cur=fnd(d);
    if (!cur){
        cout<<"NO\n";
        return;
    }
    int cnt1=0;
    while (d%cur==0){
        cnt1++;
        d/=cur;
    }
    if (d>1){
        cout<<"YES\n";
        return;
    }
    int cnt2=0;
    while (x%cur==0){
        x/=cur;
        cnt2++;
    }
    if (cnt2>cnt*(cnt1-1)){
        cout<<"NO\n";
        return;
    }




    cout<<"YES\n";

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//2121
//121
//2
//
//1 2

/**

R,S

RSAxT
SxART
xSART


**/