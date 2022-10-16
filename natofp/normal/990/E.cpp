#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
   int n,m,k;
   cin>>n>>m>>k;
   bool * ulica;
   ulica=new bool[n];
   for(int i=0;i<n;i++)
       ulica[i]=true;
   for(int i=0;i<m;i++)
   {
       int x;
       cin>>x;
       ulica[x]=false;
   }
   int * przed;
   przed=new int[n];
   int l=0;
   for(int i=0;i<n;i++)
   {
       if(ulica[i]) {l=0; przed[i]=i;}
       else {l++; przed[i]=i-l;}
   }
   int naj=0;
   int w=0;
   for(int i=0;i<n;i++)
   {
       while(ulica[i]==false && i<n) {i++; w++; }
       if(w>naj) naj=w;
       w=0;
   }
   long long int minimum=100000000000000;
    for(int i=1;i<=k;i++)
    {
        bool xd=true;
        int g;
        cin>>g;
        int index=0;
        long long int suma=0;
        while(index<n)
        {
            if(index+i>=n) {suma+=g; index=n; break;}
            if(przed[index+i]==przed[index]) {xd=false; break;}

            else
            {
                index=przed[index+i]; suma+=g;
            }
        }
        if(xd) {if(suma<minimum) minimum=suma;}

    }
 if(minimum==100000000000000 || ulica[0]==false) minimum=-1;
    cout<<minimum;
    return 0;
}