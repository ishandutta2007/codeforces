#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d;
    cin>>n>>d;
    int * tab;
    tab=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }
    sort(tab,tab+n);
    bool prawda=true;
    int licznik=-1;
    while(prawda)
    {
    licznik++;
        for(int i=n-1-licznik;i<n;i++)
        {
            if(tab[i]-tab[i-n+licznik+1]<=d) {prawda=false; break;}
        }

    }
    cout<<licznik;
    delete [] tab;
    return 0;
}