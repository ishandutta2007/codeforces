#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,y; cin>>n>>x>>y;
    string s; cin>>s;
    int res=0;
    int ile=s.length();
    for(int i=ile-1;i>=ile-x;i--)
    {
        if(s[i]=='1') res++;
    }
    if(s[ile-1-y]=='1') res--;
    else res++;
    cout<<res;
    return 0;
}