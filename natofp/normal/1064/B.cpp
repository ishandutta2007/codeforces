#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ile(int n)
{
    int w=0;
    for(int i=0;i<=30;i++)
    {
        if((1<<i)&n) w++;
    }
    return w;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
   cout<<(1<<ile(n))<<endl;
    }


    return 0;
}