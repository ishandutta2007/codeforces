#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int waga(string s)
{
    int w=0;
    for(int i=0;i<s.length();i++)
    {
        w+=s[i]-96;
    }
    return w;
}

int main()
{
    int n,k;
    cin>>n>>k;
    char * a;
    a=new char[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int w=0;
    char pop;
    string wyn="";
    pop=a[0];
    wyn+=a[0];
    k--;
    while(k)
    {
        k--;
        while(w<n && a[w]-pop<2) w++;
        if(w==n) {cout<<"-1"; return 0;}
        else
        {
            pop=a[w];
            wyn+=a[w];
        }
    }
    cout<<waga(wyn);
    return 0;
}