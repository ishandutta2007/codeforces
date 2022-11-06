#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> pp;
typedef long long ll;
typedef pair<ll,int> pl;
vector<pp> edge[300010];
vector<int> edgenum[300010];

int n,m;
ll dijk[300010];
int minedge[300010];

ll abs(ll a) { return a>0?a:-a; }

int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    int a,b,c;
    for(i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&c);
        edge   [a].push_back({b,c});
        edgenum[a].push_back(i+1);
        edge   [b].push_back({a,c});
        edgenum[b].push_back(i+1);
    }
    int u;
    scanf("%d",&u);
    for(i=1;i<=n;++i) if(i!=u) dijk[i]=1LL<<60;
    priority_queue<pl> pq;
    pq.push({0,u});
    int sz,nxt,x;
    while(pq.size()){
        pl cur=pq.top(); pq.pop();
        if(dijk[cur.second]!=-cur.first) continue;
        x=cur.second;
        for(i=0,sz=edge[x].size();i<sz;++i){
            nxt=edge[x][i].first;
            if(dijk[nxt]>edge[x][i].second-cur.first){
                dijk[nxt]=edge[x][i].second-cur.first;
                pq.push({-dijk[nxt],nxt});
            }
        }
    }
    ll ans=0, tmp;
    for(i=1;i<=n;++i){
        if(i==u) continue;
        tmp=-1;
        for(j=0,sz=edge[i].size();j<sz;++j){
            nxt=edge[i][j].first;
            if(dijk[i]-dijk[nxt]==edge[i][j].second){
                if(tmp==-1 || edge[i][tmp].second>1LL*edge[i][j].second) tmp=j;
            }
        }
        ans+=edge[i][tmp].second;
        minedge[i]=tmp;
    }
    printf("%I64d\n",ans);
    for(i=1;i<=n;++i) if(i!=u) printf("%d ",edgenum[i][minedge[i]]);
    return 0;
}