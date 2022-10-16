#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n; cin>>n;
    vector<int> a;
    for(int i=0;i<n-1;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    vector<int> res;
    res.push_back(0);
    for(int i=0;i<n-1;i++)
    {
        int t=res.back();
        res.push_back(t+a[i]);
    }
    int minn=1e6;
    int idx;
    for(int i=0;i<n;i++)
    {
        if(res[i]<minn)
        {
            minn=res[i];
            idx=i;
        }
    }
    int ile=res[idx];
    for(int i=0;i<n;i++)
    {
        res[i]-=(ile-1);
    }
    int nax=222222;
    vector<bool> xd(nax,false);
     ile=0;
     bool ok=true;
    for(int i=0;i<n;i++)
    {
        if(res[i]<1 || res[i]>n)
        {
            ok=false;
            break;
        }
        if(xd[res[i]]==false) ile++;
        xd[res[i]]=true;
    }
    if(ile!=n || ok==false) {cout<<-1;}
    else
    {
        for(int i=0;i<n;i++) cout<<res[i]<<" ";
    }
    return 0;
}