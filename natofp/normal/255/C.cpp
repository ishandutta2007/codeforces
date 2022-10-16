#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=1e6+5;
vector<int> numery[N];
set<int> aktywne;
vector<bool> a;

int ans=0;

void rob(int i,int j)
{
    if(i==j) {ans=max(ans,(int)numery[i].size()); return;}
    int wska=0;
    int wskb=0;
    int roza=numery[i].size();
    int rozb=numery[j].size();
    a.clear();
    int res=1;
    while(wska<roza || wskb<rozb)
    {
        if(wska==roza)
        {
            a.push_back(0); wskb++;
        }
        else if(wskb==rozb)
        {
            a.push_back(1); wska++;
        }
        else
        {
            if(numery[i][wska]<numery[j][wskb])
            {
                a.push_back(1); wska++;
            }
            else
            {
                a.push_back(0); wskb++;
            }
        }
    }
    for(int i=1;i<a.size();i++)
    {
        if(a[i]!=a[i-1]) res++;
    }
    ans=max(ans,res);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        numery[x].push_back(i);
        aktywne.insert(x);
    }
    vector<int> s;
    set<int>::iterator it;
    it=aktywne.begin();
    while(it!=aktywne.end())
    {
        int t=*it;
        it++;
        s.push_back(t);
    }
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s.size();j++)
        {
            rob(s[i],s[j]);
        }
    }
    cout<<ans;
    return 0;
}