#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,s;
    cin>>n>>s;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long wynik=0;
    for(int i=0;i<n/2;i++)
    {
        if(a[i]>s) wynik+=(a[i]-s);
    }
    wynik+=abs(a[n/2]-s);

    for(int i=n/2+1;i<n;i++)
    {

        if(a[i]<s) wynik+=(s-a[i]);
    }
    cout<<wynik;
    return 0;
}