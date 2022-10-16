#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct kawa
{
    int minuta;
    int numer;
};

bool por(kawa a,kawa b)
{
    return a.minuta<b.minuta;
}

long long int get(long long int i,long long int n)
{
   return (i+1000000*n)%n;
}

struct lol
{
    int minuta;
    int day;
    int nr;
};

bool por2(lol a,lol b)
{
    return a.nr<b.nr;
}

int main()
{
    int n,m,d;
    cin>>n>>m>>d;
    kawa * a;
    a=new kawa[n];
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        kawa c;
        c.numer=i;
        c.minuta=x;
        a[i]=c;
    }
    sort(a,a+n,por);
    int wsk=0;
    int naj=1;
    int i=0;
    int j=0;
    while(j<n-1)
    {
        if(a[j+1].minuta-a[i].minuta<=d) j++;
        else i++;
        if(j-i+1>naj) {naj=j-i+1; wsk=i;}

    }
    cout<<naj<<endl;
    lol * b;
    b=new lol[n];
    for(int i=0;i<n;i++)
    {
        int t=get(i-wsk,naj);
        lol xd;
        xd.day=t+1;
        xd.minuta=a[i].minuta;
        xd.nr=a[i].numer;
        b[i]=xd;

    }
    sort(b,b+n,por2);
    for(int i=0;i<n;i++) cout<<b[i].day<<" ";



    return 0;
}