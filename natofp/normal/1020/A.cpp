#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,h;
    cin>>n>>h;
    int a,b; cin>>a>>b;
    int k; cin>>k;
    while(k--)
    {
        int n1,h1,n2,h2;
        cin>>n1>>h1>>n2>>h2;
        int ans=0;
       if(n1==n2) ans=abs(h1-h2);
       else
       {
            if(h1>=a && h1<=b) ans+=abs(n2-n1);
        else
        {
            if(h1<a) ans+=a-h1;
            else ans+=h1-b;
            ans+=abs(n2-n1);
        }
        if(h1>=a && h1<=b) ans+=abs(h2-h1);
        else
        {
            if(h1<a) ans+=abs(a-h2);
            else ans+=abs(h2-b);

        }
       }
        cout<<ans<<endl;
    }
    return 0;
}