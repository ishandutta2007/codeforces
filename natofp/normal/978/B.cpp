#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   string wyraz;
   cin>>wyraz;
   int wynik=0;
    int licznik=0;
    for(int i=0;i<n;i++)
    {
        if(wyraz[i]=='x')
        {
            licznik++;
        }
        else
        {
               if(licznik>=3)
            {
                wynik+=(licznik-2);
            }
                licznik=0;
        }
    }
     if(licznik>=3)
            {
                wynik+=(licznik-2);
            }
    cout<<wynik;
    return 0;
}