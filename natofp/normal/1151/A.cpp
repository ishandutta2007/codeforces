#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ile(string s)
{
    int res=0;
    int a[4];
    a[0]=s[0]-'A';
    a[1]=s[1]-'C';
    a[2]=s[2]-'T';
    a[3]=s[3]-'G';
    for(int i=0;i<4;i++)
    {
        a[i]=abs(a[i]);
        res+=min(a[i],26-a[i]);
    }
    return res;
}

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    int res=1e9;
    for(int i=0;i<=n-4;i++)
    {
        string akt="";
        akt+=s[i];
        akt+=s[i+1];
        akt+=s[i+2];
        akt+=s[i+3];
        int wyn=ile(akt);
        res=min(wyn,res);
    }
    cout<<res;
    return 0;
}