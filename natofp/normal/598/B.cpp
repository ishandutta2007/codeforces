#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s;
    int m; cin>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--; b--;
        c%=(b-a+1);
        string v2=s;
        for(int i=a;i<=b;i++)
        {
            int k=i+c;
            if(k>b) k-=(b-a+1);
            v2[k]=s[i];
        }
        s=v2;
        
    }
    cout<<s;

    return 0;
}