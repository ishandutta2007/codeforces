#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>


using namespace std;

const int N = 4e5 + 500;

typedef pair < int , int > pii;

vector < pii > g[N];
int eg[3 * N],sol[3 * N],col[3 * N];
int n,m,s,bio[N],res1,res2,x[N],y[N],t,a,b,bb[3 * N],bb2[3 * N];
queue < int > q;

void bfs(){
    q.push(s);
    res1 = 1;
    bio[s] = 1;
    while(!q.empty()){
        int cur = q.front();
        for(int i = 0;i<g[cur].size();i++){
            if(bb[g[cur][i].second] && sol[g[cur][i].second] == 2){
                continue;
            }
            bb[g[cur][i].second] = cur;
            int nxt = g[cur][i].first;
            if(bio[nxt]) continue;
            res1++;
            bio[nxt] = 1;
            q.push(nxt);
        }
        q.pop();
    }
    memset(bio,0,sizeof(bio));
    q.push(s);
    bio[s] = 1;
    res2 = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0;i<g[cur].size();i++){
            int nxt = g[cur][i].first;
            if(bb2[g[cur][i].second] == 0 && sol[g[cur][i].second] == 2){
                bb2[g[cur][i].second] = nxt;
                continue;
            }
            if(bio[nxt]) continue;
            res2++;
            bio[nxt] = 1;
            q.push(nxt);
        }
    }
}

void load(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i = 0;i<m;i++){
        scanf("%d%d%d",&t,&a,&b);
        x[i] = a;y[i] = b;
        sol[i] = t;
        if(t == 2){
            g[b].push_back(make_pair(a,i));
        }
        g[a].push_back(make_pair(b,i));
    }
    bfs();
    printf("%d\n",res1);
    for(int i = 0;i<m;i++){
        if(sol[i] == 1) continue;
        if(bb[i] == x[i]) printf("+");
        else printf("-");
    }
    printf("\n%d\n",res2);
    for(int i = 0;i<m;i++){
        if(sol[i] == 1) continue;
        if(bb2[i] == x[i]) printf("+");
        else printf("-");
    }
}

int main(){
    load();
}