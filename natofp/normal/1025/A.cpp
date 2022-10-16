#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int tab[26];
    for(int i=0;i<26;i++)
        tab[i]=0;
    for(int i=0;i<n;i++)
    {
        char a; cin>>a;
        tab[a-97]++;
    }
    int w=0;
    int k=0;
    for(int i=0;i<26;i++)
    {
       if(tab[i]>1) {cout<<"Yes"; return 0;}
    }
    if(n==1) cout<<"Yes";
    else cout<<"No";



    return 0;
}