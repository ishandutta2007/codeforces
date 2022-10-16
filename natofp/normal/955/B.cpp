#include <iostream>
#include <string>
using namespace std;

int main()
{
    int wyniki[4];
    for(int i=0;i<4;i++)
    {
        wyniki[i]=0;
    }
    string wyraz;
    cin>>wyraz;
    int n=wyraz.length();
    int tab[122-97+1];
    for(int i=0;i<26;i++)
    {
        tab[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        char x=wyraz[i];
        tab[x-97]++;
    }
    int suma=0;
    for(int i=0;i<26;i++)
    {
        if(tab[i]>0) suma++;
    }
    int licznik=0;
    if(suma<2 || suma > 4) {cout<<"No"; return 0;}
    else if (suma == 2)
    {
        for(int i=0;i<26;i++)
        {
            if(tab[i]>0) {wyniki[licznik]=tab[i]; licznik++;}
        }
        if(wyniki[1]>=2 && wyniki[0]>=2) {cout<<"Yes"; return 0;}
        else {cout<<"No"; return 0;}
    }
    else if (suma==3)
    {
        for(int i=0;i<26;i++)
        {
            if(tab[i]>0) {wyniki[licznik]=tab[i]; licznik++;}
        }
        if(wyniki[0]>1 || wyniki[1]>1 || wyniki[2]>1)
        {
            cout<<"Yes"; return 0;
        }
        else {cout<<"No"; return 0;}
    }
    if(suma ==4) cout<<"Yes";
    return 0;
}