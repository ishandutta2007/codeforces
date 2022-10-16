#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string * tab;
    tab=new string[n];
    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }
    int tablica[26];

    for(int i=0;i<n;i++)
    {
        for(int z=0;z<26;z++)
    {
        tablica[z]=0;
    }
        string wyraz=tab[i];
        for(int j=0;j<wyraz.length();j++)
        {
            tablica[wyraz[j]-97]++;
        }
        tab[i]="";
        for(int k=0;k<26;k++)
        {
            if(tablica[k]>0) tab[i]+=(char)(k+97);

        }


    }
    int licznik=1;
    sort(tab,tab+n);
    for(int i=1;i<n;i++)
    {
        if(tab[i]!=tab[i-1]) licznik++;
    }
    delete [] tab;
    cout<<licznik;
    return 0;
}