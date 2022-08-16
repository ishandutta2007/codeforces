#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pll pair<long long,long long>

const ll N = 1e5+5;
ll inf = 9999999999999999;

map<ll,ll> train,graph[N]; 

vector<ll> parent(N,-1),dis(N,inf),vis(N,0);

void shortest_path(ll n)
{
dis[1] = 0;
parent[1] = -1;
priority_queue<pll,vector<pll>,greater<pll> > P;    
P.push({0,1});
    
ll vv = 0;    
    
while(!P.empty())
{
    
if(vv==n) break;    
    
auto x = P.top();
P.pop();
    
if(vis[x.S]==1) continue; 
    
vis[x.S] = 1;
vv++;    
    
for(auto z : graph[x.S])    
{
if(vis[z.F]) continue;
if(dis[z.F] >= dis[x.S] + z.S)
{
dis[z.F] = dis[x.S] + z.S;
P.push({dis[z.F],z.F});
parent[z.F]=x.S;    
}
    
}

}
       
}

int main()   
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
    
ll u,v,w,n,m,k,i,j;
cin >> n >> m >> k;
    
f(i,m)
{
cin >> u >> v >> w; 

if(graph[u].find(v) != graph[u].end() )     
{
graph[u][v] = min(graph[u][v],w);    
graph[v][u] = min(graph[v][u],w);    
}
else
{
graph[u][v] = w;    
graph[v][u] = w;    
}
    
}
    
f(i,k)
{
cin >> v >> w;
    
if(graph[1].find(v) != graph[1].end() )
{
 if(graph[1][v] > w)   
 {
graph[1][v] = graph[v][1] = w;
train[v] = 1;
 }
}
else
{
graph[1][v] = graph[v][1] = w;
train[v] = 1;
}
    
}
    
shortest_path(n);    
    
set<ll> g;    
    
vector<short> jt(N,0);    
   
for(i=2;i<=n;i++)
{
 ll z = i;   
 
 while(z != -1 ) 
 { 
     if(jt[z]==1) break;
     if(parent[z]==1 && train.find(z)!=train.end()) g.insert(z);
     jt[z] = 1;
     z=parent[z];
 }     
    
}
        
cout << k-g.size();    
}