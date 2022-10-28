#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 300001;
int n,m;
vector< pair < int , int > > v[N];
long long dist[N];
int weight[N];
int pre[N];
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n ; ++i){
        dist[i] = 999999999999999LL;
    }
    for(int i = 1; i<=m ; ++i){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].pb(mp(b,i));
        v[b].pb(mp(a,i));
        weight[i] = c;
    }
    int so ;
    scanf("%d",&so);
    priority_queue< pair < long long , int > > q;
    q.push(mp(0LL,so));
    dist[so] = 0LL;
    pre[so]=0;
    weight[0] = 0;
    while(!q.empty()){
        int node = q.top().second;
        q.pop();
        int x = v[node].size();
        while(x--){
            int next = v[node][x].first;
            int id = v[node][x].second;
            int weigh = weight[id];
            if(dist[next] > dist[node] + weigh){
                dist[next ] = dist[node] + weigh;
                q.push(mp(-dist[next],next));
                pre[next] = id;
            }
            else if(dist[next] ==dist[node] + weigh){
                if(weight[pre[next]] > weigh){
                    pre[next] =id;
                }
            }
        }
    }
    long long sum = 0;
    for(int i = 1;i<=n;++i){
        sum+=weight[pre[i]];
    }
    printf("%I64d\n",sum);
    for(int i = 1;i<=n;++i){
        if(i!=so){
            printf("%d ",pre[i]);
        }
    }
}