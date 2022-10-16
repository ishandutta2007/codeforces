#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<pair<int,int>> free;
    vector<vector<int>> mod(m);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mod[a[i]%m].push_back(i);
    }
    int k=n/m;
    long long w=0;
    for(int i=0;i<2*m;i++)
    {
        int cur=i%m;
        while(mod[cur].size()>k)
        {
            int elem=mod[cur].back();
            mod[cur].pop_back();
            free.push_back(make_pair(elem,i));
        }
        while(mod[cur].size()<k && !free.empty())
        {
            int elem=free.back().first;
            int j=free.back().second;
            free.pop_back();
            w+=(i-j);
            mod[cur].push_back(elem+i-j);
            a[elem]+=(i-j);
        }
    }
    cout<<w<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}