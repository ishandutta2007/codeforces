#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    int n,m;
    cin>>n>>m;
    int x;
    for(int i=0;i<2*m;i++) cin>>x;
    for(int i=0;i<n;i++)
    {
        if(i%2==0) cout<<"0";
        else cout<<"1";
    }

    return 0;
}