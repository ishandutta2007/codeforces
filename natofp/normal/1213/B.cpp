#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> a;
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int cnt=0;
        a.clear();
        for(int i=0;i<n;i++)
        {
            int x; cin>>x; a.push_back(x);
        }
        int xd=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]>xd) cnt++;
            xd=min(xd,a[i]);
        }
        cout<<cnt<<"\n";
    }
    return 0;
}