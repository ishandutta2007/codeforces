#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dlugosc(int n)
{
    int i=0;
    while(n) {n/=10; i++;}
    return i;
}

long long pot(long long mod,long long p,long long n)
{
    for(int i=0;i<p;i++)
    {
        n*=10;
        n%=mod;
    }
    return n;
}

int main()
{
   int n,k;
   cin>>n>>k;
   long long int * a;
   a=new long long int[n];
   map<long long int,long long int>  tab[11];
   for(int i=0;i<n;i++)
   {
       long long int t; cin>>t;
       a[i]=t;
       int d=dlugosc(t);
       tab[d][t%k]++;
   }
   long long wynik=0;
   for(int i=0;i<n;i++)
   {
       long long int t=a[i];
       for(int j=0;j<10;j++)
       {
           long long int z=pot(k,j+1,t);
           if(tab[j+1].count((k-z)%k)>0) wynik+=tab[j+1][(k-z)%k];
       }

    if(((pot(k,dlugosc(t),t)+t)%k)==0) wynik--;
   }

   cout<<wynik;
    return 0;
}