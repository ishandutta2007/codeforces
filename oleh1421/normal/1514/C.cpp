#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=500010;
const ll mod=1000000007;
void solve(){
    vector<int>v;
    ll n;cin>>n;
    for (ll i=1;i<n;i++){
        if (__gcd(i,n)==1) v.push_back(i);
    }
    ll m=1;
    for (int i:v){
        m*=i*1ll;
        m%=n;
    }
    if (m!=1) v.pop_back();
    cout<<v.size()<<endl;
    for (int i:v) cout<<i<<" ";
    cout<<endl;
}
int32_t main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
///C=MEX(A)^B + MEX(B)^A
///MEX(C)=MEX(A)^MEX(B)
///A - DONE
//a b c
//a b c d

//0 1 2 3

//0 1 2 3
//0 1 2 3
//
//1+1+1+1+

/**
1 3
0.0 0.1 0.5 0.2
**/