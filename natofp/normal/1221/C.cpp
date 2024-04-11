#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        int c,m,x; cin>>c>>m>>x;
        int a=min(c,m);
        a=min(a,x);
        int res=a;
        c-=a;
        m-=a;
        x-=a;
        if(c==0 || m==0)
        {
            cout<<res<<endl; continue;
        }
        else
        {
            if(m>2*c || c>2*m) res+=min(c,m);
            else res+=(c+m)/3;
        }
        cout<<res<<endl;
    }
    return 0;
}