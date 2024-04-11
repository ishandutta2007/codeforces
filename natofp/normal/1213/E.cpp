#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n;
void wypisz(string s)
{
    for(int j=0;j<n;j++) cout<<s;
    exit(0);
}

bool okk(string s,string a,string b)
{
    string t;
    for(int i=0;i<n;i++) t+=s[0];
    for(int i=0;i<n;i++) t+=s[1];
    for(int i=0;i<n;i++) t+=s[2];
    for(int i=0;i<3*n-1;i++)
    {
        if(t[i]==a[0] && t[i+1]==a[1]) return false;
        if(t[i]==b[0] && t[i+1]==b[1]) return false;
    }
    return true;
}

void koncz(string s)
{
    string t;
    for(int i=0;i<n;i++) t+=s[0];
    for(int i=0;i<n;i++) t+=s[1];
    for(int i=0;i<n;i++) t+=s[2];
    cout<<t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<"YES"<<endl;
    cin>>n;
    string s,t; cin>>s>>t;
    bool ok[3];
    ok[0]=ok[1]=ok[2]=false;
    if(s[0]==s[1] && t[0]==t[1])
    {
        for(int j=0;j<n;j++)
        {
            cout<<"abc";
        }
        return 0;
    }
    else if(s[0]==s[1] || t[0]==t[1])
    {
        string x;
        if(s[0]==s[1]) x=t;
        else x=s;
        if(x=="ab") wypisz("cba");
        if(x=="ac") wypisz("cab");
        if(x=="ba") wypisz("bca");
        if(x=="bc") wypisz("bac");
        if(x=="ca") wypisz("cba");
        if(x=="cb") wypisz("cab");
    }
    bool xd;
    xd=okk("abc",s,t);
    if(xd)
    {
        koncz("abc");
        return 0;
    }
    xd=okk("acb",s,t);
    if(xd)
    {
        koncz("acb");
        return 0;
    }
    xd=okk("bac",s,t);
    if(xd)
    {
        koncz("bac");
        return 0;
    }
    xd=okk("bca",s,t);
    if(xd)
    {
        koncz("bca");
        return 0;
    }
    xd=okk("cab",s,t);
    if(xd)
    {
        koncz("cab");
        return 0;
    }
    xd=okk("cba",s,t);
    if(xd)
    {
        koncz("cba");
        return 0;
    }

    return 0;
}