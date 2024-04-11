#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
int t; cin>>t;
while(t--)
{

    int n,v,l,r;
    cin>>n>>v>>l>>r;
    int ans=0;
    ans+=n/v;
    int k=l%v;
    r/=v;
    r*=v;
    l/=v;
    l*=v;
    if(k!=0) l+=v;
    ans-=(r-l)/v+1;
    cout<<ans<<endl;
}
    return 0;
}