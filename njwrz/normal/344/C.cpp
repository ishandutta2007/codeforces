#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll a,b;
    cin>>a>>b;
    ll ans=0;
    while(1){
        if(a<b)swap(a,b);
        ll k=a/b;
        a-=k*b;
        ans+=k;
        if(a%b==0)break;
    }
    cout<<ans;
    return 0;
}