#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool ok = false;
string s;

bool czy(string p)
{
    for(int i=0;i<p.length()/2;i++)
    {
        if(p[i]!=p[p.length()-1-i]) return false;
    }
    return true;
}

void proba(int x)
{
    string pom="";
    for(int i=0;i<x;i++) pom+=s[i];
    string pom2="";
    for(int i=x;i<s.length();i++)
    {
        pom2+=s[i];
    }
    string wyn=pom2+pom;
    if(wyn!=s && czy(wyn)==true)
    {
        cout<<1<<endl; exit(0);
    }
}

int main()
{
    cin>>s;
    int t=s.length();
    if(t%2==0)
    {
        for(int i=1;i<t;i++)
        {
            if(s[i]!=s[0])
            {
                ok=true;
                break;
            }
        }
        if(ok==false) {cout<<"Impossible"; return 0;}
    }
    else
    {
        for(int i=0;i<t;i++)
        {
            if(i==t/2) continue;
            if(s[i]!=s[0])
            {
                ok=true;
                break;
            }

        }
        if(ok==false) {cout<<"Impossible"; return 0;}
    }
    for(int i=0;i<t;i++)
    {
        proba(i);
    }
    cout<<2;

    return 0;
}