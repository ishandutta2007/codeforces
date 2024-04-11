#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int szukaj(int * tab,int n,bool * czy)
{
    int index=-1;
    int a=0; int b=0;
    int naj=10000000;
    if(tab[0]%2==0) a++;
    else b++;
    for(int i=1;i<n-1;i++)
    {
        if(a==b)
        {
            if((abs(tab[i]-tab[i-1])<naj) && czy[i]==false) {index=i; naj=abs(tab[i]-tab[i-1]);}
        }
        if(tab[i]%2==0) a++;
        else b++;
    }
    return index;
}

int main()
{
   int n,b;
   cin>>n>>b;
   int * a;
   a=new int[n];
   for(int i=0;i<n;i++) cin>>a[i];
   bool * czy;
   czy=new bool[n];
   for(int i=0;i<n;i++) czy[i]=false;
   int w=0;
    while(b>=0)
    {

        int x=szukaj(a,n,czy);
        if(x==-1) {break;}
        else
        {
            int k=abs(a[x]-a[x-1]);
            if(b>=k) {b-=k; w++; czy[x]=true;}
            else {break;}
        }
    }
    cout<<w;
    return 0;
}