#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        if(k%3!=0)
        {
            if(n%3==0) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
        else if(k%3==0)
        {
            int ile=k/3;
            int dlugosc=(ile-1)*3+4;
            n%=dlugosc;
            if(n<=(ile-1)*3)
            {
                if(n%3==0) cout<<"Bob"<<endl;
                else cout<<"Alice"<<endl;
            }
            else
            {
                n-=(ile-1)*3;
                if(n==0) cout<<"Bob"<<endl;
                else cout<<"Alice"<<endl;
            }
        }
    }
    return 0;
}