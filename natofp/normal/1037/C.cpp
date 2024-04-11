#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    string a,b;
    cin>>n;
    cin>>a>>b;
    long long wynik=0;
    bool xd=true;
    for(int i=0;i<a.length()-1;i++)
    {
        if(a[i]!=b[i] && a[i+1]!=b[i+1] && a[i]!=a[i+1]) {wynik++; i++; if(i==(n-1)) {xd=false;}}
        else if(a[i]!=b[i] && a[i+1]!=b[i+1]) {wynik++;}
        else if(a[i]!=b[i])
        {
            wynik++;
        }
    }
    if(xd==true && a[n-1]!=b[n-1]) wynik++;
    cout<<wynik;
    return 0;
}