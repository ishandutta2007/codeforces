#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s; cin>>s;
    int n=s.length();
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a') res++;
    }
    cout<<min(res*2-1,n);
    return 0;
}