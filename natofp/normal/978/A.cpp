#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x=0;
    int n;
    cin>>n;
    map <int,int> a;
    int * tab;
    tab=new int[n];
    for(int i=0;i<n;i++)
        cin>>tab[i];
    bool * wynik;
    wynik=new bool[n];
    for(int i=0;i<n;i++)
    {
        wynik[i]=true;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[tab[i]]==0)
        {
            x++;
            a[tab[i]]=1;
        }
        else wynik[i]=false;
    }
    cout<<x<<endl;
    for(int i=0;i<n;i++)
    {
        if(wynik[i]==true) cout<<tab[i]<<" ";
    }
    return 0;
}