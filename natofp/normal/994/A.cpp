#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool czy(int x,vector<int> tab)
{
    for(int i=0;i<tab.size();i++)
        if(tab[i]==x) return true;
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector <int> a;
    vector <int> b;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }
    vector <int> odp;
    for(int i=0;i<n;i++)
    {
        if(czy(a[i],b)) odp.push_back(a[i]);
    }
    for(int i=0;i<odp.size();i++)
        cout<<odp[i]<<" ";
    return 0;
}