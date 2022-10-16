#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct knight
{
    int power;
    int coins;
    int number;
};

bool por(knight a,knight b)
{
    return a.power<b.power;
}

int znajdzmin(int * tablica,int n)
{
    int index=0;
    int naj=2000000000;
    for(int i=0;i<n;i++)
    {
        if(tablica[i]<naj) {naj=tablica[i]; index=i;}
    }
    return index;
}

int main()
{
    int n,k;
    cin>>n>>k;
    knight * lista;
    lista=new knight[n];
    for(int i=0;i<n;i++)
    {
        lista[i].number=i;
        int x; cin>>x;
        lista[i].power=x;
    }
    for(int i=0;i<n;i++)
    {
        int xd;
        cin>>xd;
        lista[i].coins=xd;
    }
    long long  * wyniki;
    wyniki=new long long int[n];
    int * zbior;
    zbior = new int[k];
    for(int i=0;i<k;i++)
        zbior[i]=0;
    sort(lista,lista+n,por);
    for(int i=0;i<n;i++)
    {
        long long int wynik=0;
        for(int i=0;i<k;i++)
            wynik+=zbior[i];
        wyniki[lista[i].number]=lista[i].coins+wynik;
        int p=lista[i].coins;
        if(p>zbior[znajdzmin(zbior,k)]) zbior[znajdzmin(zbior,k)]=p;
    }

    for(int i=0;i<n;i++)
        cout<<wyniki[i]<<" ";

    return 0;
}