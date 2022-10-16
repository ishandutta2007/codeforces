#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    int res=100;
    int ile=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='-') ile--;
        else ile++;
    }
    for(int i=0;i<=100;i++)
    {
    bool ok = true;
        int akt=i;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='-') akt--;
            else akt++;
            if(akt<0)
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            res=i; break;
        }
    }
    cout<<res+ile;
    return 0;
}