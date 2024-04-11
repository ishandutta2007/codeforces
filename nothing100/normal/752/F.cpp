#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
struct se{
    int x,y;
    bool operator <(const se &a) const{
        return ((x>a.x)||((x==a.x)&&(y<a.y)));
    }
};
vector<int> edge[MAXN],que[MAXN];
set<se> s;
int n,k,hav[MAXN],f[MAXN],cnt;
void dfs(int x,int y){
    for (int i=0;i<edge[x].size();i++)
    if (edge[x][i]!=y){
        dfs(edge[x][i],x);
        hav[x]+=hav[edge[x][i]];
    }
    hav[x]+=f[x];
}
void redfs(int x,int y,int z){
    if (f[x]) que[z].push_back(x);
    for (int i=0;i<edge[x].size();i++)
    if (edge[x][i]!=y) redfs(edge[x][i],x,z);
}
void solve(int x,int y){
    int bo=1;
    for (int i=0;i<edge[x].size();i++)
    if (edge[x][i]!=y&&hav[edge[x][i]]>k){
        solve(edge[x][i],x);
        bo=0;
    }
    if (bo){
        printf("%d\n",x);
        for (int i=0;i<edge[x].size();i++){
            redfs(edge[x][i],x,cnt);
            se tmp;
            tmp.x=que[cnt].size();
            tmp.y=cnt++;
            if (tmp.x) s.insert(tmp);
        }
        if (f[x]){
            se tmp;
            que[cnt].push_back(x);
            tmp.x=1;
            tmp.y=cnt++;
            s.insert(tmp);
        }
        while (!s.empty()){
            set<se>::iterator it=s.begin();
            int tmp1=it->y,tmp2;
            printf("%d ",que[tmp1][(it->x)-1]);
            que[tmp1].pop_back();
            s.erase(it);
            it=s.begin();
            tmp2=it->y;
            printf("%d %d\n",que[tmp2][(it->x)-1],x);
            que[tmp2].pop_back();
            s.erase(it);
            se tmp;
            tmp.x=que[tmp1].size();
            tmp.y=tmp1;
            if (tmp.x) s.insert(tmp);
            tmp.x=que[tmp2].size();
            tmp.y=tmp2;
            if (tmp.x) s.insert(tmp);
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<n;i++){
        int o,p;
        scanf("%d%d",&o,&p);
        edge[o].push_back(p);
        edge[p].push_back(o);
    }
    for (int i=0;i<2*k;i++){
        int o;
        scanf("%d",&o);
        f[o]=1;
    }
    printf("1\n");
    dfs(1,0);
    solve(1,0);
}