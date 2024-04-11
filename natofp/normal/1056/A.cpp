#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> a(101,0);
    for(int i=0;i<n;i++)
    {
        int r; cin>>r;
        for(int j=0;j<r;j++)
        {
            int x; cin>>x;
            a[x]++;
        }
    }
    for(int i=1;i<=100;i++)
    {
        if(a[i]==n) cout<<i<<" ";
    }
    return 0;
}