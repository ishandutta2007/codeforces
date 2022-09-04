#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n,ans=1;
    cin>>n;
    while((ans*(ans+1))/2<=n){
        n-=(ans*(ans+1))/2;
        ans++;
    }
    cout<<ans-1;
}