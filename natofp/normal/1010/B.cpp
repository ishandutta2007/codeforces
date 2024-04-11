#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int bs(int m,int * tab,int n)
{
    int i=0;
    int a=1; int b=m;
    while(a<b)
    {
        int srodek=(a+b)/2;
        cout<<flush<<srodek<<endl; 
        int d; cin>>d;
        d*=tab[i%n]; i++;
        if(d==1)
        {
            a=srodek+1;
        }
        else if(d==-1)
        {
            b=srodek-1;
        }
        else if(d==0) {return srodek;}

    }
    return a;

}


int main()
{
    int m,n;
    cin>>m>>n;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++)
    {
        cout<<m<<endl;
        
        int d; cin>>d;
        if(d==-1) a[i]=1;
        else a[i]=-1;
        if(d==0) {cout<<flush<<m;   exit(0); }

    }
    cout<<flush<<bs(m,a,n);  exit(0);

}