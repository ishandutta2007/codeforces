#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
const int maxSize=3*1e5+5;
//Dijkstra
vector<vector<pair<int,int> > > graf(maxSize);

ll dist[maxSize];
int parent[maxSize];
int n;
void Dijkstra(int source)
{
    set<pair<ll,int> > d;
    d.insert(make_pair(0,source));
    ll inf=1e15;
    for(int i=2;i<=n;i++)
    {
        d.insert(make_pair(inf,i));
    }
    int visited[n+1]={};
    ll vrednosti[n+1];
    fill(vrednosti,vrednosti+n+1,inf);
    vrednosti[source]=0;
    parent[source]=source;
    while(!d.empty())
    {
        pair<int,int> curr=*d.begin();
        //printf("Usao za %i %i\n",curr.first,curr.second);
        visited[curr.second]=1;
        d.erase(d.begin());
        dist[curr.second]=vrednosti[curr.second];
        for(int i=0;i<graf[curr.second].size();i++)
        {
            int sled=graf[curr.second][i].first;
            ll tez=(ll)graf[curr.second][i].second+dist[curr.second];
            if(visited[sled]==0&&vrednosti[sled]>tez)
            {
                d.erase(make_pair(vrednosti[sled],sled));
                d.insert(make_pair(tez,sled));
                vrednosti[sled]=tez;
                parent[sled]=curr.second;
            }
        }
    }
}

map<pair<int,int>,int> edge_id;
set<pair<int,int> > edges;
vector<vector<int> > tre(maxSize);
vector<int> subtree(maxSize);
vector<int> leaves;
void dfs(int tr,int par)
{
    //printf("Usao za %i\n",tr);
    subtree[tr]=1;
    for(auto p:tre[tr])
    {
        if(p==par)
            continue;
        subtree[tr]+=1;
        dfs(p,tr);
    }
    if(subtree[tr]==1&&tr!=1)
        leaves.pb(tr);
}

int main()
{
    int m,k;
    scanf("%i %i %i",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        scanf("%i %i %i",&x,&y,&w);
        edge_id[{x,y}]=i+1;
        edge_id[{y,x}]=i+1;
        graf[x].pb({y,w});
        graf[y].pb({x,w});
    }
    Dijkstra(1);
    for(int i=2;i<=n;i++)
    {
        tre[i].pb(parent[i]);
        tre[parent[i]].pb(i);
        edges.insert({min(i,(int)parent[i]),max(i,(int)parent[i])});
        //printf("Dodajem %i-%i  %lld\n",min(i,(int)parent[i]),max(i,(int)parent[i]),dist[i]);
        //printf("%i dolazi iz %i\n",i,parent[i]);
    }
    dfs(1,-1);
    assert(edges.size()==n-1);
    /*for(int i=2;i<=n;i++)
        printf("%i\n",subtree[i]);*/
    while(edges.size()>k)
    {
        //printf("%i\n",leaves.size());
        if(leaves.size()==0)
        {
            while(true)
            {

            }
        }
        int i=leaves.back();
        leaves.pop_back();
        edges.erase({min(i,(int)parent[i]),max(i,(int)parent[i])});
        subtree[parent[i]]--;
        if(subtree[parent[i]]==1)
            leaves.pb(parent[i]);
    }
    printf("%i\n",edges.size());
    for(auto p:edges)
    {
        printf("%i ",edge_id[{p.first,p.second}]);
    }
    return 0;
}