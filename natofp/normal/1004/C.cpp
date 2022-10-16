#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n;
    cin>>n;
    int * ilosc;
    ilosc=new int[100001];
    int * rightmost;
    rightmost=new int[100001];
    for(int i=0;i<=100000;i++)
    {
        ilosc[i]=0;
        rightmost[i]=-1;
    }
    int * unikalne;
    unikalne=new int [100001];
    for(int i=0;i<=100000;i++) unikalne[i]=0;
    int licznik=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        unikalne[i]=licznik;
        if(ilosc[x]==0) licznik++;
        ilosc[x]++;
        rightmost[x]=i;
    }
    long long total=0;
    for(int i=0;i<=100000;i++)
    {
        if(ilosc[i]!=0)
        {
            total+=unikalne[rightmost[i]];
        }
    }
    cout<<total;

    return 0;
}