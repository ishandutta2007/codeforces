#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int a,b,c; cin>>a>>b>>c;
        int res=0;
        while(b>=1 && c>=2)
        {
            b--;
            c-=2;
            res+=3;
        }
        res+=3*min(a,b/2);
        cout<<res<<endl;
    }
    return 0;
}