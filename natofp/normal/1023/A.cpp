#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool check(string a)
{
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='*') return true;
    }
    return false;
}

int main()
{
    string a,b;
    int n,m;
    cin>>n>>m>>a>>b;
    bool c=check(a);
    if(c==false)
    {
        if(a!=b) cout<<"NO";
        else cout<<"YES";
        return 0;
    }
    bool xd=true;
    if(n-1>m) {cout<<"NO"; return 0;}
    int i=0;
    while(a[i]!='*')
    {
        if(a[i]!=b[i]) xd=false;
        i++;
    }

    int j=n-1;
    while(a[j]!='*')
    {
        if(a[j]!=b[j+b.length()-a.length()]) xd=false;
        j--;
    }
    if(xd) cout<<"YES";
    else cout<<"NO";


    return 0;
}