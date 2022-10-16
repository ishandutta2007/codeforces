#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int m; cin>>m;
    int * gry;
    gry=new int[n];
    int * bills;
    bills=new int[m];
    for(int i=0;i<n;i++) cin>>gry[i];
    for(int i=0;i<m;i++) cin>>bills[i];
    int a=0; int b=0;
    int w=0;
    while(a<n && b<m)
    {
        if(gry[a]<=bills[b]) {w++; a++; b++;}
        else {a++;}
    }
    cout<<w;

    return 0;
}