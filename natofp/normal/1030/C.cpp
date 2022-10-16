#include <iostream>
#include <bits/stdc++.h>

using namespace std;



bool czyv2(int *x,int n,int ile)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=x[i];
    }
    if(sum%ile!=0) return false;
    sum/=ile;
    int akt=0;
    for(int i=0;i<n;i++)
    {
        akt+=x[i];
        if(akt>sum) return false;
        if(akt==sum) akt=0;
    }
    return true;
}

int main()
{
    int n; cin>>n;
    int * a;
    a=new int[n];
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        a[i]=s[i]-48;
    }
    bool xd=false;
    for(int i=2;i<=n;i++)
    {
        if(czyv2(a,n,i)) {xd=true;}
    }
    if(xd) cout<<"YES";
    else cout<<"NO";
    return 0;
}