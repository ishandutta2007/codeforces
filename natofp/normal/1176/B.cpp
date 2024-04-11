#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a,b,c;
        a=b=c=0;
        for(int i=0;i<n;i++)
        {
            int x; cin>>x;
            if(x%3==0) a++;
            else if(x%3==1) b++;
            else c++;
        }
        int res=a+min(b,c);
        int xd=min(b,c);
        b-=xd; c-=xd;
        res+=b/3;
        res+=c/3;
        cout<<res<<endl;
    }
    return 0;
}