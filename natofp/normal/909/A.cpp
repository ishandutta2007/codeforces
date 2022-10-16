#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    string a,b; cin>>a>>b;
    string xd="";
    xd=a[0];
    char x=b[0];
    for(int i=1;i<a.size();i++)
    {
        if(a[i]<x)
        {
            xd+=a[i];
        }
        else break;
    }
    xd+=x;
    cout<<xd;
    return 0;
}