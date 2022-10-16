#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m; cin>>n>>m;
    int * a=new int[m];
    for(int i=0;i<m;i++) cin>>a[i];
    vector<int> ile(n,0);
    int xd=n;
    for(int i=0;i<m;i++)
    {
        int t=a[i];
        t--;
        ile[t]++;
        if(ile[t]==1) xd--;
        if(xd==0)
        {
            for(int j=0;j<n;j++) ile[j]--;
            cout<<"1";
            for(int j=0;j<n;j++) if(ile[j]==0) xd++;
        }
        else cout<<"0";
    }
    return 0;
}