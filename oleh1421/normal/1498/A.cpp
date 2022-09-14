#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
const ll inf=1e14+1ll;
ll sum(ll n){
    ll res=0ll;
    while (n){
        res+=n%10ll;
        n/=10ll;
    }
    return res;
}
void solve(){
    ll n;cin>>n;
    while (__gcd(n,sum(n))==1) n++;
    cout<<n<<endl;
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
/**
70368744177661
70368744177662
70368744177663





85184372088830
93824992237018
1
35184372088883

35184372088883
35184372088884

46912496118508

14*15/2=105
80368744177662
70368744177764
70368744177661
60368744177661

100000000000000
89999999999999
**/