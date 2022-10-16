#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int * a;
   a=new int[n];
   for(int i=0;i<n;i++)
    cin>>a[i];
    int * wejscie;
    wejscie=new int[n];
    for(int i=0;i<n;i++)
    {
        int x=max(0,a[i]-i);
        wejscie[i]=x/n;
        if(x%n!=0) wejscie[i]++;
    }
    int index=1;
    int odp=1000000001;
    for(int i=0;i<n;i++)
    {
        if(wejscie[i]<odp) {odp=wejscie[i]; index=i+1;}
    }
    cout<<index;
    return 0;
}