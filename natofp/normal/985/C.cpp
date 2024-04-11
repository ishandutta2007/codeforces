#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,l;
    cin>>n>>k>>l;
    int * tab;
    tab=new int[n*k];
    for(int i=0;i<n*k;i++)
        cin>>tab[i];
    sort(tab,tab+n*k);
    int index=0;
    for(int i=0;i<n*k;i++)
    {
        if(tab[i]-tab[0]<=l) index=i;
    }
    index++;
    int a=index-n;
    if(a<0) {cout<<"0";}
    else
    {
        long long suma=0;
        int licznik=0;
        for(int i=0;i<n;i++)
        {
            suma+=tab[licznik];
            licznik++;
            if(a>=k-1) {licznik+=k-1; a-=(k-1);}
            else {licznik+=a; a=0;}
        }
        cout<<suma;
    }

    return 0;
}