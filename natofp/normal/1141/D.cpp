#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;

bool czy1[nax];
bool czy2[nax];


int main()
{
    int n; cin>>n;
    for(int i=0;i<=n;i++)
    {
        czy1[i]=false;
        czy2[i]=false;
    }
    string a;
    string b;
    cin>>a>>b;
    vector<pair<int,int> > res;
    for(int i=0;i<26;i++)
    {
        char t='a'+i;
        vector<int> idx1;
        vector<int> idx2;
        for(int j=0;j<n;j++)
        {
            if(a[j]==t) idx1.push_back(j);
            if(b[j]==t) idx2.push_back(j);
        }
        for(int j=0;j<min(idx1.size(),idx2.size());j++)
        {
            res.push_back({idx1[j],idx2[j]});
            czy1[idx1[j]]=true;
            czy2[idx2[j]]=true;
        }
    }
    vector<int> idx1;
    vector<int> idx2;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='?') idx1.push_back(i);
        if(b[i]=='?') idx2.push_back(i);
    }
    int wsk1=0;
    int wsk2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!='?' && czy1[i]==false)
        {
            if(wsk2<idx2.size())
            {
                res.push_back({i,idx2[wsk2]});
                czy1[i]=false;
                wsk2++;
            }
        }
        if(b[i]!='?' && czy2[i]==false)
        {
            if(wsk1<idx1.size())
            {
                res.push_back({idx1[wsk1],i});
                czy2[i]=false;
                wsk1++;
            }
        }
    }
    while(wsk1<idx1.size() && wsk2<idx2.size())
    {
        res.push_back({idx1[wsk1],idx2[wsk2]});
        wsk1++;
        wsk2++;
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i].first+1<<" "<<res[i].second+1<<endl;
    }
    return 0;
}