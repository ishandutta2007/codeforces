#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> tab(n);
    for(int i=0;i<n;i++)
        cin>>tab[i];
    map<int,int> wynik;
    int licznik=0;
    int index=0;
    for(int i=0;i<n;i++)
    {
        int a=tab[i];
        wynik[a]=wynik[a-1]+1;
        if(wynik[a]>licznik)
        {
            licznik=wynik[a];
            index=a;
        }
    }
    vector <int> ans(licznik);
    int it=0;
    int szukaj=index-licznik+1;
    for(int i=0;i<n;i++)
    {
        if(tab[i]==szukaj)
        {
            ans[it]=i;
            it++;
            szukaj++;
        }
    }
    cout<<licznik<<endl;
    for(int i=0;i<licznik;i++)
    {
        cout<<ans[i]+1<<" ";
    }
    return 0;
}