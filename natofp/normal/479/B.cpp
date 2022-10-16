#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<pair<int,int> > a;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back({x,i+1});
    }
    sort(a.begin(),a.end());
    vector<pair<int,int> > res;
    int ans=a[n-1].first-a[0].first;
    for(int i=0;i<k;i++)
    {
        if(a[n-1].first-a[0].first==0) break;
        pair<int,int> x,y;
        res.push_back({a[n-1].second,a[0].second});
        a[n-1].first--;
        a[0].first++;
        sort(a.begin(),a.end());
    }
    ans=min(ans,a[n-1].first-a[0].first);
    cout<<ans<<" "<<res.size()<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return 0;
}