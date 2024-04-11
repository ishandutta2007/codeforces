#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    long long int res=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='2' || s[i]=='4' || s[i]=='6' || s[i]=='8') res+=i+1;
    }
    cout<<res;

    return 0;
}