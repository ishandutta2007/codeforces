#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    vector<pair<int,int> >a;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back({x,i});
    }
    sort(a.begin(),a.end());
    vector<int> ans(n);
    int ile=1;

    for(int i=n-1;i>=0;i--)
    {
        int k=n-a[i].first;
        int t=a[i].first;
        k--;
        ans[a[i].second]=ile;
        while(k>0)
        {
            k--; i--;
            if(i<0 || a[i].first!=t) {cout<<"Impossible"; return 0;}
            ans[a[i].second]=ile;

        }
        ile++;
    }
    cout<<"Possible"<<endl;
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}