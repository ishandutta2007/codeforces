#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=1e6+5;
vector<pair<int,int> > adj[2*nax];
vector<vector<int> > a(2*nax);
vector<vector<long long int> > pref(2*nax);
int n,m;
int kraw[2*nax];

long long int ile(int jaki,int l,int r)
{
    if(l==0) return pref[jaki][r];
    return pref[jaki][r]-pref[jaki][l-1];
}

long long int solve(int v,int h)
{
    if(h<0) return 0;
    if(v>n || v<1) return 0;
    int lo=0;
    int hi=a[v].size()-1;
    while(lo+1<hi)
    {
        int mid=(lo+hi)/2;
        if(a[v][mid]<=h) lo=mid;
        else hi=mid;
    }
    int idx;
    if(a[v][hi]<=h) idx=hi;
    else idx=hi-1;
    long long int res=(long long int)h*(idx+1);
    res-=ile(v,0,idx);
    return res;
}

void dfs(int v,int p)
{
    vector<int> res;
    res.push_back(0);
    vector<int> a1;
    vector<int> a2;
    for(int i=0;i<adj[v].size();i++)
    {
        int to=adj[v][i].first;
        if(to==p) continue;
        dfs(to,v);
    }
    a1=a[v*2];
    a2=a[v*2+1];
    int roza1=a1.size();
    int roza2=a2.size();
    int wska1=0;
    int wska2=0;
    int kraw1=kraw[v*2-1];
    int kraw2=kraw[v*2];
    while(wska1<roza1 || wska2<roza2)
    {
        if(wska1==roza1)
        {
            res.push_back(a2[wska2]+kraw2);
            wska2++;
            continue;
        }
        else if(wska2==roza2)
        {
            res.push_back(a1[wska1]+kraw1);
            wska1++;
            continue;
        }
        else
        {
            if(a1[wska1]+kraw1<=a2[wska2]+kraw2)
            {
                res.push_back(a1[wska1]+kraw1);
                wska1++;
            }
            else
            {
                res.push_back(a2[wska2]+kraw2);
                wska2++;
            }
        }
    }
    a[v]=res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++)
    {
        int waga; cin>>waga;
        int to=(i+1)/2;
        adj[i+1].push_back({to,waga});
        adj[to].push_back({i+1,waga});
        kraw[i]=waga;
    }
    dfs(1,1);
    //int idx=1;
    //for(int i=0;i<a[idx].size();i++) cout<<a[idx][i]<<" ";
    for(int i=1;i<=n;i++)
    {
        vector<long long int> suma;
        long long int akt=0;
        for(int j=0;j<a[i].size();j++)
        {
            akt+=a[i][j];
            suma.push_back(akt);
        }
        pref[i]=suma;
    }
    while(m--)
    {
        int start;
        int ile;
        cin>>start>>ile;
        long long int wynik=0;
        wynik+=solve(start,ile);
        while(start>1)
        {
            ile-=kraw[start-1];
            if(ile>0) wynik+=ile;
            int mod=start%2;
            start/=2;
            if(mod==0)
            {
                wynik+=solve(start*2+1,ile-kraw[start*2]);
            }
            else
            {
                wynik+=solve(start*2,ile-kraw[start*2-1]);
            }
        }
        cout<<wynik<<"\n";

    }
    return 0;
}