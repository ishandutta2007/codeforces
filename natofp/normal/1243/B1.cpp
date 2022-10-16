#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int ile[26];

string ss,tt;



int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        cin>>ss>>tt;
        vector<int> idx;
        for(int i=0;i<n;i++)
        {
            if(ss[i]!=tt[i]) idx.push_back(i);
        }
        if(idx.size()==1 || idx.size()>2)
        {
            cout<<"No"<<endl; continue;
        }
        if(idx.size()==0)
        {
            cout<<"Yes"<<endl; continue;
        }
        if(ss[idx[0]]==ss[idx[1]] && tt[idx[1]]==tt[idx[0]]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;


    }
    return 0;
}