#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    int x;
    scanf("%d",&x);
    return x;
}
#define pb push_back
#define mp make_pair
struct data{
    int first;
    int edge_used;
    int prev;
    data(){
        first=0;
        edge_used = 0;
        prev=0;
    }
};
vector<pair<int,int> > v[100005];
bool edge[100005]={0};
pair <int,int> edges[100005];
data nodes[100005];
bool visited[100005]={0};
bool used[100005]={0};
int dist[100005];
int main(){
    int n=scan(),m=scan(); 
    for(int i=1;i<=m;i++){
        int x=scan(),y=scan(),z=scan();
        v[x].pb(mp(y,i));
        v[y].pb(mp(x,i));
        edge[i]=z;
        edges[i]=mp(x,y);
    }
    queue<int> q;
    q.push(1);
    visited[1]=1;
    for(int i=0;i<=n;i++)dist[i]=999999;
    dist[1]=0;
    bool aslivisit[100001]={0};
    while(!q.empty()){
        int node=q.front();
        aslivisit[node]=1;
        q.pop();
        int x=v[node].size();
        int num = nodes[node].first;
        for(int i=0;i<x;i++){
            int next = v[node][i].first;
            if(aslivisit[next])continue;
            int num2 = num;
            if(edge[v[node][i].second]==0){
                num2++;
            }
            if(!visited[next]){
                visited[next]=1;
                q.push(next);
                nodes[next].first=num2;
                nodes[next].edge_used=v[node][i].second;
                nodes[next].prev=node;
                dist[next]=dist[node]+1;
            }
            else if(dist[next]>=dist[node]+1){
                if(num2<nodes[next].first){
                    nodes[next].first=num2;
                    nodes[next].edge_used=v[node][i].second;
                    nodes[next].prev=node;
                    //q.push(next);
                }
            }
        }
    }
    int cur = n;
    while(cur!=0){
        used[nodes[cur].edge_used]=1;
        cur=nodes[cur].prev;
    }
    int counter=0;
    queue< pair<pair<int,int>,bool> > ans;
    for(int i=1;i<=m;i++){
        if(!used[i]&&edge[i]==1){
            counter++;
            ans.push(mp(edges[i],0));
        }
        else if(used[i]&&edge[i]==0){
            counter++;
            ans.push(mp(edges[i],1));
        }
    }
    printf("%d\n",counter);
    while(!ans.empty()){
        printf("%d %d %d\n",ans.front().first.first,ans.front().first.second,ans.front().second);
        ans.pop();
    }
}