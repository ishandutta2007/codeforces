#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct vertex{
    int num;
    int dis;
    int trs;
    vertex(){}
    vertex(int _num, int _dis, int _trs){
        num=_num;
        dis=_dis;
        trs=_trs;
    }
    bool operator<(const vertex &v)const{
        return dis>v.dis;
    }
};
struct compare{
    bool operator()(vertex &v1, vertex &v2){
        if(v1.trs==v2.trs) return v1.dis>v2.dis;
        return v1.trs>v2.trs;
    }
};
vector<vertex> adj[200200][20];
priority_queue<vertex> pq;
priority_queue<vertex, vector<vertex>, compare> pq2;
pair<int, int> dist[200200][20];
bool visited[200200][20];
int n, m;

void dijkstra(int s){
    pq.push(vertex(s, 0, 0));
    while(!pq.empty()){
        vertex tmp=pq.top();
        pq.pop();
        if (visited[tmp.num][tmp.trs]) continue;
        visited[tmp.num][tmp.trs]=1;
        dist[tmp.num][tmp.trs]=make_pair(tmp.dis, 0);
        int tnum=tmp.num, ttrs=tmp.trs, tdis=tmp.dis;
        //printf("%d %d %d\n", tnum, tdis, ttrs);
        for (auto &v:adj[tnum][ttrs]){
            if (visited[v.num][v.trs]) continue;
            pq.push(vertex(v.num, tdis+v.dis, v.trs));
        }
    }
}

void dijkstra2(int s){
    for (int i=1;i<=n;i++){
        for (int j=0;j<2;j++) visited[i][j]=0;
    }
    pq2.push(vertex(s, 0, 0));
    while(!pq2.empty()){
        vertex tmp=pq2.top();
        pq2.pop();
        if (visited[tmp.num][(tmp.trs)%2]) continue;
        visited[tmp.num][(tmp.trs)%2]=1;
        dist[tmp.num][tmp.trs%2]=make_pair(tmp.dis, tmp.trs);
        for (auto &v:adj[tmp.num][tmp.trs%2]){
            if (v.trs>1) continue;
            if (visited[v.num][v.trs]) continue;
            int tt=0;
            if (tmp.trs%2!=v.trs) tt=1;
            pq2.push(vertex(v.num, tmp.dis+v.dis-tt, tmp.trs+tt));
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1;i<=n;i++){
        for (int j=0;j<20;j++) dist[i][j]=make_pair(0, -1);
    }
    for (int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        for (int j=0;j<20;j++){
            if (j%2==0) adj[a][j].push_back(vertex(b, 1, j));
            else adj[b][j].push_back(vertex(a, 1, j));
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<20;j++) adj[i][j-1].push_back(vertex(i, 1<<(j-1), j));
    }
    dijkstra(1);
    bool test=0;
    for (int i=0;i<20;i++){
        if (dist[n][i].second!=-1) test=1;
    }
    ll ans=1, mod=998244353;
    if (!test){
        for (int i=1;i<=n;i++) adj[i][1].push_back(vertex(i, 1, 0));
        dijkstra2(1);
    }
    else{
        ans=1e18;
        for (int j=0;j<20;j++){
            if (dist[n][j].second==-1) continue;
            ans=min(ans, (ll)dist[n][j].first);
        }
        printf("%lld", ans);
        return 0;
    }
    ll tmp;
    if (dist[n][0].second>dist[n][1].second) tmp=1;
    else if (dist[n][0].second==dist[n][1].second){
        if (dist[n][0].first>dist[n][1].first) tmp=1;
        else tmp=0;
    }
    else tmp=0;
    for (int i=0;i<dist[n][tmp].second;i++) ans=(ans*2)%mod;
    ans--;
    ans=(ans+dist[n][tmp].first)%mod;
    printf("%lld", ans);
    return 0;
}