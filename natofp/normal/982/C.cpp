#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int wyniki[300000+1];
vector<int> a[3000001];
int odp=0;
void dfs(int v,int p=-1)
{
    wyniki[v]=1;
    for(int i=0;i<a[v].size();i++)
    {
        if(a[v][i]==p) continue;
        dfs(a[v][i],v);
        wyniki[v]+=wyniki[a[v][i]];
    }
    if(wyniki[v]%2==0) odp++;
}



int main()
{
    int n;
    cin>>n;

    if(n%2==1) cout<<"-1";
    else
    {
        for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    cout<<odp-1;
    }
    return 0;
}