#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool czy(char x)
{
    if(x=='a' || x=='i' || x=='u' || x=='o' || x=='e') return true;
    return false;
}

int main()
{
    string s,t; cin>>s>>t;
    if(s.length()!=t.length()) {cout<<"No"; return 0;}
    for(int i=0;i<s.length();i++)
    {
        if(czy(s[i])!=czy(t[i])) {cout<<"No"; return 0;}
    }
    cout<<"Yes";
    return 0;
}