#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

long long int a(long long int a)
{
    if(a<0) return (-1)*a;
    return a;
}

int main()
{
    int xd;
    bool prawda;
    int wynik;
    int a,b,r;
    int licznik;
    int naj=1000000;
    int n;
    cin>>n;
    int * tab;
    tab=new int[n];

    for(int i=0;i<n;i++)
        cin>>tab[i];

    if(n==1 && n==2) {cout<<"0"; return 0;}
    else
    {
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            prawda=true;
            licznik=0;
            a=tab[0]+i;
            b=tab[1]+j;
            if(i!=0) licznik++;
            if(j!=0) licznik++;
            r=b-a;
            for(int c=2;c<n;c++)
            {
                wynik=tab[c]-a;
                if(abs(wynik-c*r)<=1)
                {
                    if(wynik!=c*r) licznik++;

                }
                else prawda=false;

            }
            if(prawda)
            {
                if (licznik<naj) naj=licznik;
            }
        }
    }

    }
if(naj==1000000) cout<<"-1";
else cout<<naj;

    return 0;
}