#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,K;
   cin>>n>>K;
   vector <int> a(n);
    int * tab;
    tab=new int[n];
    for(int i=0;i<n;i++)
        cin>>tab[i];
    sort(tab,tab+n);
    reverse(tab,tab+n);
    int wynik=0;
    int w=1;
    for(int i=n-1;i>0;i--)
    {
        if(tab[i-1]==tab[i]) w++;
        else
        {
              if(tab[i-1]<=tab[i]+K) wynik+=w;
              w=1;
        }

    }
    cout<<n-wynik;

    return 0;
}