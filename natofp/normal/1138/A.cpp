#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> xd;
    int akt=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1]) akt++;
        else
        {
            xd.push_back(akt);
            akt=1;
        }
    }
    xd.push_back(akt);
    int ans=0;
    for(int i=1;i<xd.size();i++) ans=max(ans,min(xd[i],xd[i-1])*2);
    cout<<ans;
    return 0;
}