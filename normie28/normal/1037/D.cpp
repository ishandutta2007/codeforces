#include <bits/stdc++.h>
using namespace std;
   int n;
    
    map<pair<int,int>,int>ed;
    int deg[200009];
    int val[200009];
int main()
{
  cin>>n;
    fill(deg,deg+200000,0);
    for(int i=1; i<=n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        ed[make_pair(u,v)] = 1;
        ed[make_pair(v,u)] = 1;
        deg[u]++;
        deg[v]++;
    }
    for(int i=1; i<=n; i++)cin>>val[i];
    if(val[1]!=1)cout<<"NO"<<endl;
    else{
    int id = 2;
    int loc = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; id<=n && j<=deg[val[i]]; j++)
        {
            if(ed[make_pair(val[i],val[id])]!=1 && ed[make_pair(val[id],val[i])]!=1)
            {
                loc = 0;
                break;
            }
            deg[val[id]]--;
            ++id;
        }
        if(!loc)
            break;
    }
    if(loc)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    }
}