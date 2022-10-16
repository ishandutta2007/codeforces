#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n; cin>>n;
    vector<pair<int,int > > a;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back({x,i});
    }
    vector<int> odp;
    int res=0;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        odp.push_back(a[i].second+1);
        res+=(i*a[i].first)+1;
    }
    cout<<res<<endl;
    for(int i=0;i<n;i++) cout<<odp[i]<<" ";
    return 0;
}