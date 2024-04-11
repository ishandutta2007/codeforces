#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    int a[5];
    for(int i=0;i<5;i++) a[i]=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='o') a[0]++;
        if(s[i]=='n') a[1]++;
        if(s[i]=='e') a[2]++;
        if(s[i]=='r') a[3]++;
        if(s[i]=='z') a[4]++;
    }
    for(int i=100000;i>=0;i--)
    {
        int t[5];
        for(int j=0;j<5;j++)
        {
            t[j]=a[j];
        }
        t[0]-=i;
        t[1]-=i;
        t[2]-=i;
        bool ok = true;
        for(int j=0;j<5;j++)
        {
            if(t[j]<0)
            {
                ok = false;
            }

        }
        if(ok==false) continue;
        int ile=t[0];
        for(int j=2;j<=4;j++)
        {
            if(t[j]!=ile) ok = false;
        }
        if(ok==false) continue;
        for(int k=0;k<i;k++) cout<<"1"<<" ";
        for(int k=0;k<ile;k++) cout<<"0"<<" ";
        return 0;
    }
    return 0;
}