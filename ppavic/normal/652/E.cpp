#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair <int,int> pii;

const int N = 3*1e5+500;

int n,m;
int a,b,c;

pii mp(int a,int b){
    return make_pair(min(a,b),max(a,b));
}

map < pair <int,int> ,int > forbid;
map < pair <int,int> ,int > tre;
vector <int> graf[N];
vector <int> komp[N];
vector <int> arte[N];
int low[N],dis[N],timer = 1,bio[N],ima[N],cnt = 1;

int dfs(int x,int last){
    if(dis[x] != 0) return dis[x];
    dis[x] = timer++;
    low[x] = dis[x];
    for(int i = 0;i<graf[x].size();i++){
        if(graf[x][i] == last) continue;
        int moze = int(dis[graf[x][i]] == 0);
        int t = dfs(graf[x][i],x);
        if(t > dis[x] && moze) forbid[mp(x,graf[x][i])] = 1;
        low[x] = min(low[x],t);
    }
    return low[x];
}

void dfs2(int x,int last){
    bio[x] = cnt;
    for(int i = 0;i<graf[x].size();i++){
        if(forbid.find(mp(x,graf[x][i])) != forbid.end()) continue;
        if(tre[mp(x,graf[x][i])]) ima[cnt] = 1;
        if(bio[graf[x][i]] != 0) continue;
        dfs2(graf[x][i],x);
    }
}

int didit = 0,start,end;

void dfs3(int x,int last,int im){
    if(x == bio[end] && !didit){
        if(im) printf("YES\n");
        else printf("NO\n");
        didit = 1;
    }
    for(int i = 0;i<komp[x].size();i++){
        if(komp[x][i] == last) continue;
        dfs3(komp[x][i],x,im|ima[komp[x][i]]|arte[x][i]);
    }
}




int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        graf[a].push_back(b);
        graf[b].push_back(a);
        tre[mp(a,b)] = c;
    }
    dfs(1,-1);
    for(int i = 1;i<=n;i++){
        if(!bio[i]) {dfs2(i,-1);cnt++;}
    }
    for(map< pair <int,int> , int >::iterator i = forbid.begin();i!=forbid.end();i++){
        if(bio[i->first.first] == bio[i->first.second]) continue;
        komp[bio[i->first.first]].push_back(bio[i->first.second]);
        komp[bio[i->first.second]].push_back(bio[i->first.first]);
        arte[bio[i->first.first]].push_back(tre[mp(i->first.first,i->first.second)]);
        arte[bio[i->first.second]].push_back(tre[mp(i->first.first,i->first.second)]);
        //printf("%d <=> %d\n",bio[i->first.first],bio[i->first.second]);
    }
    scanf("%d %d",&start,&end);
    dfs3(bio[start],-1,ima[bio[start]]);
    if(!didit){
        printf("NO\n");
    }
}