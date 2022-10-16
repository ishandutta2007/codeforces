#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string a="";
        for(int i=0;i<n;i++)
        {
            a+='a'+i%k;
        }
        cout<<a<<endl;
    }

    return 0;
}