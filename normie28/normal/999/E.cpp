#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 10000;
 
int V, E, cnt, dfsn[MAX], SN, sn[MAX];
vector<int> adj[MAX];
bool finished[MAX]; 
stack<int> S;
vector<vector<int>> SCC;
int DFS(int curr){
    dfsn[curr] = ++cnt; 
    S.push(curr); 
    int result = dfsn[curr];
    for(int next: adj[curr]){
        if(dfsn[next] == 0) result = min(result, DFS(next));
        else if(!finished[next]) result = min(result, dfsn[next]);
    }
    if(result == dfsn[curr]){
        vector<int> currSCC;
        while(1){
            int t = S.top();
            S.pop();
            currSCC.push_back(t);
            finished[t] = true;
            sn[t] = SN;
            if(t == curr) break;
        }
        sort(currSCC.begin(), currSCC.end());
        SCC.push_back(currSCC);
        SN++;
    }
    return result;
}
 
vector<int> sAdj[500000];
int sStart; 
int sOutdegree[500000] = {0}; 
int vist[5001]={0,};
void dfs2(int num)
{
    vist[num]=1;
    for(auto next :sAdj[num])
    {
        if(vist[next]==0)
        {
            dfs2(next);
        }
    }
    
}
 
int main(){
    int N, M, cash[500000];
    bool hasRest[500000] = {0};
    scanf("%d %d", &N, &M);
    int start;
    scanf("%d",&start);
    for(int i=0; i<M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
    }
    for(int i=0; i<N; i++)
        if(dfsn[i] == 0) DFS(i);
    start--;
    for(int i=0; i<N; i++){
        int si = sn[i];
        if(i == start) sStart = si;
        for(int j: adj[i]){
            int sj = sn[j];
            if(si == sj) continue;
            
            sAdj[si].push_back(sj);
            sOutdegree[sj]++;
        }
    }
    dfs2(sStart);
    int anw=0;
    for(int i=0; i<SN; i++)
    {
        if(sOutdegree[i]==0&&i!=sStart)
        {
            anw++;
        }
    }
    cout<<anw;
}