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
    if((n-res)%2!=0) {cout<<":("; return 0;}
    string t;
    string t2;
    int bez=(n-res)/2;
    for(int i=0;i<bez+res;i++)
    {
        t+=s[i];
    }
    for(int i=bez+res;i<n;i++)
    {
        t2+=s[i];
    }
    int idx=0;
    for(int i=0;i<t.length();i++)
    {
        if(t[i]=='a') continue;
        if(t[i]!=t2[idx]) {cout<<":("; return 0;}
        idx++;
    }
    cout<<t;
    return 0;
}