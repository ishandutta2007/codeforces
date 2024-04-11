#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> a;
    int ile=0;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
        if(abs(x)%2==1) ile++;
    }
    ile/=2;
    for(int i=0;i<n;i++)
    {
        if(abs(a[i])%2==0) cout<<a[i]/2<<endl;
        else
        {
            if(ile)
            {
                if(a[i]>=0) cout<<a[i]/2<<endl;
                else cout<<a[i]/2-1<<endl;
                ile--;
            }
            else
            {
                if(a[i]>=0) cout<<a[i]/2+1<<endl;
                else cout<<a[i]/2<<endl;
            }
        }
    }
    return 0;
}