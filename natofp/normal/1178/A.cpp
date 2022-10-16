#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int g; cin>>g;
    vector<pair<int,int> > a;
    for(int i=0;i<n-1;i++)
    {
        int x; cin>>x;
        a.push_back({x,i+2});
    }
    sort(a.begin(),a.end());
    int suma=0;
    suma+=g;
    vector<int> ans;
    int ile=g;
    for(int i=0;i<a.size();i++) suma+=a[i].first;
    for(int i=0;i<a.size();i++)
    {
        if(a[i].first*2>g) break;
        ile+=a[i].first;
        ans.push_back(a[i].second);
    }
    if(ile*2>suma)
    {
        cout<<ans.size()+1<<endl;
        cout<<1<<" ";
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    }
    else cout<<0;
    return 0;
}