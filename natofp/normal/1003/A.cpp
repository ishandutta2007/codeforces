#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int tab[101];
    for(int i=0;i<101;i++) tab[i]=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        tab[x]++;

    }
    int naj=0;
    for(int i=0;i<101;i++)
        if(tab[i]>naj) naj=tab[i];
    cout<<naj;
    return 0;
}