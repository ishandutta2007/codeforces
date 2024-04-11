#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int ab(int a)
{
    if(a<0) return -1*a;
    return a;
}

int main()
{
    int n;
    cin>>n;
    int * tab;
    tab=new int[n/2];
    for(int i=0;i<n/2;i++)
        cin>>tab[i];
    sort(tab,tab+n/2);
    int a=0;
    int b=0;
    for(int i=0;i<n/2;i++)
    {
        a+=ab((n-2*i-tab[n/2-i-1]));
    }
    for(int i=0;i<n/2;i++)
    {
        b+=ab((n-2*i-1-tab[n/2-i-1]));
    }
    if(a<b) cout<<a;
    else cout<<b;
    return 0;
}