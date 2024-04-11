#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int a,b,c; cin>>a>>b>>c;
        int k=a+c;
        if(k<=b)
        {
            cout<<0<<endl; continue;
        }
        int maxx=k;
        int srodek=(k+b)/2;
        srodek++;
        int minn=max(a,srodek);
        cout<<maxx-minn+1<<endl;


    }
    return 0;
}