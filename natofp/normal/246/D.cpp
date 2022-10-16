#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
vector<int> color(N+5);
vector<bool> ile(N+5,false);
vector<set<int> > a(N+5);

int main()
{
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        color[i]=x;
        ile[x]=true;
    }
    for(int i=0;i<m;i++)
    {
        int x,y; cin>>x>>y;
        if(color[x]!=color[y])
        {
            a[color[x]].insert(color[y]);
            a[color[y]].insert(color[x]);
        }
    }
    int naj=-1; int idx=-1;
    for(int i=N;i>=1;i--)
    {

        if(ile[i]==true && (int)a[i].size()>=naj)
        {
            idx=i;
            naj=a[i].size();
        }
    }
    cout<<idx;
    return 0;
}