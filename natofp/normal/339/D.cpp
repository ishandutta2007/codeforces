#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int roz;
int tree[1111111];

void update(int v,int val)
{
    v+=roz/2;
    tree[v]=val;
    bool ok=true;
    v/=2;
    while(v>0)
    {
        if(ok)
        {
            tree[v]=tree[v*2]|tree[v*2+1];
        }
        else
        {
             tree[v]=tree[v*2]^tree[v*2+1];
        }
        v/=2;
        ok=!ok;
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(tree,0,sizeof tree);
    int n,m;
    cin>>n>>m;
    roz=(1<<(n+1));
    for(int i=0;i<roz/2;i++)
    {
        cin>>tree[roz/2+i];
    }
    bool ok=true;
    for(int i=roz/2-1;i>=1;i--)
    {
        if(ok)
        {
            tree[i]=tree[i*2]|tree[i*2+1];
        }
        else
        {
            tree[i]=tree[i*2]^tree[i*2+1];
        }
        if(__builtin_popcount(i)==1) ok=!ok;
    }
    for(int i=0;i<m;i++)
    {
        int p,b; cin>>p>>b;
        p--;
        update(p,b);
        cout<<tree[1]<<endl;
    }
    return 0;
}