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
    sort(tab.begin(),tab.end());
    if (n%2==1) cout<<tab[n/2];
    else cout<<tab[n/2-1];

    return 0;
}