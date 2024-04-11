#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=111;
int a[nax][nax];

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    int ilepocz=0;
    int ilek=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') ilepocz++;
        if(s[i]==')') ilek++;
    }
    if(n%2==1) {cout<<":("; return 0;}
    int ile=n/2;
    if(ilepocz>ile || ilek>ile) {cout<<":("; return 0;}
    ile-=ilepocz;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?')
        {
            if(ile>0) {s[i]='('; ile--;}
            else s[i]=')';
        }
    }
    int cnta=0;
    int cntb=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') cnta++;
        else cntb++;
        if(i<n-1)
        {
            if(cntb>=cnta) {cout<<":("; return 0;}
        }
    }
    cout<<s;
    return 0;
}