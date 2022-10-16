#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    vector<pair<int,int> > a;
    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        a.push_back({x,y});
    }
    int k; cin>>k;
    int ile=-1;
    for(int i=0;i<n;i++)
    {
        if(k<=a[i].second)
        {
            ile=i;
            break;
        }
    }
    cout<<n-ile;
    return 0;
}