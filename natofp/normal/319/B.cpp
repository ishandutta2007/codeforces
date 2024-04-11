#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> DEATH(n,0);
    stack<pair<int,int>> s;
    int ans=0;
    DEATH[0]=-1;
    s.push({0,-1});
    for(int i=1;i<n;i++)
    {
        while(s.size()>0 && a[s.top().first]<a[i])
        {
            DEATH[i]=max(DEATH[i],s.top().second+1);
            s.pop();
        }
        if(s.size()==0) DEATH[i]=-1;
        s.push({i,DEATH[i]});
        ans=max(ans,DEATH[i]+1);
    }
    cout<<ans;
    return 0;
}