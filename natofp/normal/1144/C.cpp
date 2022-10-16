#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;

int main()
{
    int t[nax];
    memset(t,0,sizeof t);
    int n; cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        t[x]++;
        a.push_back(x);
    }
    for(int i=0;i<nax;i++)
    {
        if(t[i]>2) {cout<<"No"; return 0;}
    }
    sort(a.begin(),a.end());
    vector<int> ros;
    vector<int> mal;
    for(int i=0;i<nax;i++)
    {
        if(t[i]>0)
        {
            t[i]--;
            ros.push_back(i);
        }
    }
    for(int i=nax-1;i>=0;i--)
    {
        if(t[i]>0) mal.push_back(i);
    }
    cout<<"YES"<<endl;
    cout<<ros.size()<<endl;
    for(int i=0;i<ros.size();i++) cout<<ros[i]<<" ";
    cout<<endl;
    cout<<mal.size()<<endl;
    for(int i=0;i<mal.size();i++) cout<<mal[i]<<" ";
    return 0;
}