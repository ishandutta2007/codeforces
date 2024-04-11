#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int u,d,l,r;
    u=d=l=r=0;
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U') u++;
        if(s[i]=='R') r++;
        if(s[i]=='L') l++;
        if(s[i]=='D') d++;
    }
    int res=min(l,r)+min(u,d);
    res*=2;
    cout<<res;
    return 0;
}