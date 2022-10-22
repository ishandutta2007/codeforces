#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll a,b,mod=1000000007;
    cin>>a>>b;
    ll ans=0,d=(b*(b-1)/2)%mod;
    for(int i=1;i<=a;i++){
        ans=(ans+(i*b+1)%mod*d)%mod;
    }
    cout<<ans;
    return 0;
}