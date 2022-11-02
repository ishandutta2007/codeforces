#include <bits/stdc++.h>
#define maxn 300300
using namespace std;
#define pb push_back
#define pii pair<ll,ll>
#define pip pair<ll,pii>
#define debug 
#define ll long long
#define move ouehfri
#define left cjsbsoiyafg

#define sq 300


map<pii,int> edge;
map<pii,int> good;
map<pii,int> move;
vector<int> L[maxn];

int nice[maxn];
int nicenice[maxn];
int neig[maxn];

int vis[maxn];
int pai[maxn];
int dist[maxn];


main(){
    
    int n,m;
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b), a--, b--;
        L[a].pb(b);
        L[b].pb(a);
        edge[pii(a,b)] = edge[pii(b,a)] = 1;
    }
    int good1 = 0;
    int move1;
    
    
    for(int i=0;i<n;i++)
        if(L[i].size() > sq){
            
            for(int j=0;j<n;j++)
                nice[j] = 1, nicenice[j] = 0;
            nice[i] = 0;
            for(int j=0;j<L[i].size();j++)
                nice[L[i][j]] = 0;
            for(int j=0;j<n;j++)
                for(int k=0;k<L[j].size();k++)
                    if(nice[L[j][k]])
                        nicenice[j] = 1;
            int g1 = -1, g2 = -1;
            for(int j=0;j<L[i].size();j++)
                if(nicenice[L[i][j]]){
                    if(g1 == -1)
                        g1 = L[i][j];
                    else
                        g2 = L[i][j];
                }
            for(int j=0;j<L[i].size();j++){
                if(g1 != -1 && g1 != L[i][j]){
                    good[pii(L[i][j],i)] = 1;
                    move[pii(L[i][j],i)] = g1;
                }
                if(g2 != -1 && g2 != L[i][j]){
                    good[pii(L[i][j],i)] = 1;
                    move[pii(L[i][j],i)] = g2;
                }
            }
            
            if(g1 != -1 && i == 0){
                good1 = 1;
                move1 = g1;
            }
            
        }
        
    int cur = 0;
    for(int i=0;i<n;i++)
        if(L[i].size() <= sq){
            cur++;
            for(int j=0;j<L[i].size();j++)
                neig[L[i][j]] = cur;
            neig[i] = cur;
            int g1 = -1, g2 = -1;
            for(int j=0;j<L[i].size();j++){
                int k = L[i][j];
                for(int l=0;l<min((int)L[k].size(),1+(int)L[i].size());l++)
                    if(neig[L[k][l]] != cur){
                        if(g1 == -1)
                            g1 = k;
                        else if(g1 != k)
                            g2 = k;
                    }
            }
            debug("i %d g1 %d g2 %d\n",i+1,g1+1,g2+1);
            for(int j=0;j<L[i].size();j++){
                if(g1 != -1 && g1 != L[i][j]){
                    good[pii(L[i][j],i)] = 1;
                    move[pii(L[i][j],i)] = g1;
                }
                if(g2 != -1 && g2 != L[i][j]){
                    good[pii(L[i][j],i)] = 1;
                    move[pii(L[i][j],i)] = g2;
                }
            }
            if(g1 != -1 && i == 0){
                good1 = 1;
                move1 = g1;
            }
        }
   

    queue<int> Q;
    Q.push(0);
    
    for(int i=1;i<n;i++)
        dist[i] = maxn;
    
    int bestCyc = maxn;
    int cyc;
    int vai;
    
    while(Q.size()){
        int u = Q.front();
        debug("bfs %d\n",u+1);
        Q.pop();
        vis[u] = 1;
        for(int i=0;i<L[u].size();i++){
            if(good[pii(u,L[u][i])] && bestCyc == maxn && dist[u] + 1 < dist[L[u][i]]){
                bestCyc = dist[u] + 5;
                cyc = L[u][i];
                vai = move[pii(u,L[u][i])];
            }
            if(dist[u] + 1 < dist[L[u][i]]){
                dist[L[u][i]] = dist[u] + 1;
                Q.push(L[u][i]);
                pai[L[u][i]] = u;
            }
        }
    }
    debug("ok %d %d %d %d\n",dist[n-1],bestCyc,good1,move1);
    
    for(int i=0;i<L[0].size();i++){
        int u = L[0][i];
        if(good1 &&  dist[n-1] > 4 && bestCyc > 4){debug("ofk");
            printf("4\n");
            printf("1 ");
            int uu = move1;
            printf("%d ",1+uu);
            for(int j=1;j<L[uu].size();j++)
                if(!edge[pii(L[uu][j],0)]){
                    printf("%d ",1+L[uu][j]);
                    break;
                }
            printf("1 %d\n",n);
            return 0;
        }
    }
    
    if(bestCyc == maxn && dist[n-1] == maxn){
        printf("-1\n");
        return 0;
    }
    
    if(dist[n-1] < bestCyc){
        vector<int> resp;
        int vx = n-1;
        while(vx){
            resp.pb(vx);
            vx = pai[vx];
        }
        resp.pb(0);
        reverse(resp.begin(),resp.end());
        printf("%d\n",resp.size()-1);
        for(int i=0;i<resp.size();i++)
            printf("%d ",1+resp[i]);
        printf("\n");
        return 0;
    }
    
    else {
        int vx = cyc;
        vector<int> resp;
        while(vx){
            resp.pb(vx);
            vx = pai[vx];
        }
        resp.pb(0);
        reverse(resp.begin(),resp.end());
        resp.pb(vai);
        for(int i=0;i<L[vai].size();i++)
            if(!edge[pii(cyc,L[vai][i])] && L[vai][i] != cyc){
                resp.pb(L[vai][i]);
                break;
            }
        
        resp.pb(cyc);
        resp.pb(n-1);
        printf("%d\n",resp.size()-1);
        for(int i=0;i<resp.size();i++)
            printf("%d ",1+resp[i]);
        printf("\n");
        return 0;
    }
    printf("-1\n");
}