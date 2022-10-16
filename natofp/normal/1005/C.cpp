#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    map <int,int> mapa;
    for(int i=0;i<n;i++)
    {
        mapa[a[i]]++;
    }
    int w=0;
    for(int i=0;i<n;i++)
    {
        bool wynik=false;
         for(int j=0;j<=30;j++)
    {

        int x=(1<<j)-a[i];
        if(mapa[x]>1 || (mapa[x]==1 && a[i]!=x)) wynik=true;

    }
    if(!wynik) w++;
    }
    cout<<w;

    return 0;
}