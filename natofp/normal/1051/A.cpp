#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int check(string s)
{
    bool a,b,c;
    a=false; b=false; c=false;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9') a=true;
        else if(s[i]>='a' && s[i]<='z') b=true;
        else if(s[i]>='A' && s[i]<='Z') c=true;

    }
    int ans=0;
    if(a==false) ans++;
    if(b==false) ans++;
    if(c==false) ans++;
    return ans;
}

string zrob(string s)
{
    for(int i=0;i<s.length();i++)
    {
        string t=s;
        t[i]='0';
        if(check(t)==0) return t;
        t[i]='a';
        if(check(t)==0) return t;
        t[i]='A';
        if(check(t)==0) return t;
    }
    for(int i=0;i<s.length()-1;i++)
    {
        string t=s;
        t[i]='0';
        t[i+1]='a';
        if(check(t)==0) return t;
        t[i]='0';
        t[i+1]='A';
        if(check(t)==0) return t;
        t[i]='a';
        t[i+1]='0';
        if(check(t)==0) return t;
        t[i]='a';
        t[i+1]='A';
        if(check(t)==0) return t;
        t[i]='Z';

        t[i+1]='a';
        if(check(t)==0) return t;
        t[i]='Z';
        t[i+1]='0';
        if(check(t)==0) return t;
    }

}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        int x=check(s);
        if(x==0)
        {
            cout<<s<<endl; continue;
        }
        else cout<<zrob(s)<<endl;


    }
    return 0;
}