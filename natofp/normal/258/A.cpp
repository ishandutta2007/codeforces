#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{

    string s; cin>>s;
    int x=-1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0') {x=i; break;}
    }
    if(x==-1) x=s.length()-1;
    for(int i=0;i<s.length();i++)
    {
        if(i!=x) cout<<s[i];
    }
    return 0;
}