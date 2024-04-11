#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin>>a>>b;
    int ile=0;
    for(int i=1;i<b.length();i++)
    {
        if(b[i]!=b[i-1]) ile++;
    }
    int wynik=0;
    for(int i=0;i<b.length();i++)
    {
        if(a[i]!=b[i]) wynik++;
    }
    int res=0;
    if(wynik%2==0) res++;
    int c=b.length();
    for(int i=b.length();i<a.length();i++)
    {
        wynik+=ile;
        wynik%=2;
        wynik+=(a[i]!=b[c-1]);
        wynik+=(a[i-c]!=b[0]);
        if(wynik%2==0) res++;
    }
    cout<<res;
    return 0;
}