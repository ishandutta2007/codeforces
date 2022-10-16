#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,x,b,y;
    cin>>n>>a>>x>>b>>y;
    while(1)
    {
        if(a==b)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        if(a==x) break;
        if(b==y) break;
        a++;
        b--;
        if(a==n+1) a=1;
        if(b==0) b=n;
    }
    cout<<"NO"<<endl;
    return 0;
}