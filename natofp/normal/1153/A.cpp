#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int idx=-1;
    int res=1e9;
    int n,t; cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        int a,b; cin>>a>>b;
        if(a>t)
        {
            int wynik=a-t;

            if(wynik<res)
            {
                res=wynik;
                idx=i+1;
                continue;
            }
            continue;
        }
        int a1=a%b;
        int a2=t%b;
        int wynik=a1-a2;
        if(wynik<0) wynik+=b;
        if(wynik<res)
        {
            res=wynik;
            idx=i+1;
        }
    }

    cout<<idx;
    return 0;
}