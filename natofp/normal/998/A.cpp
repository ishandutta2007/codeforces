#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int * tab;
    tab=new int[n];
    for(int i=0;i<n;i++)
        cin>>tab[i];

    if(n==1 || (n==2 && tab[0]==tab[1])) {cout<<"-1"; return 0;}
    int index=0;



        int naj=10000;
        for(int i=0;i<n;i++)
        if(tab[i]<naj) {naj=tab[i]; index=i;}

    cout<<n-1<<endl;
    for(int i=0;i<n;i++)
    {
        if(i!=index) cout<<i+1<<" ";
    }
    return 0;
}