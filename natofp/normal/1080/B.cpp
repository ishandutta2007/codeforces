#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        long long int l,r;
        cin>>l>>r;
        long long int ans=0;
        if(l%2==r%2)
        {
            if(l%2==1) ans-=l;
            else ans+=l;
            l++;

        }
        if(l%2==1) ans+=(r-l+1)/2;
        else ans-=(r-l+1)/2;

        cout<<ans<<endl;
    }
    return 0;
}