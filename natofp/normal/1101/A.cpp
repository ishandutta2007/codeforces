#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        long long a,b,c; cin>>a>>b>>c;
        if(c<a) {cout<<c<<endl; continue;}
        else
        {
             long long t=b%c;
            if(t==0) cout<<b+c;
            else cout<<b+(c-t);
            cout<<endl;
        }
    }
    return 0;
}