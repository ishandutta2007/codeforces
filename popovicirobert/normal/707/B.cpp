#include <cstdio>
#include <vector>
#define MAXN 100000
#define MAXQ (1<<17)
#define INF 1000000000000000000LL
struct Edge{
   int nod;
   int l;
};
std::vector <Edge> G[MAXN+1];
int cod[MAXQ];
long long dist[MAXN+1];
int vf[MAXN+1];
char good[MAXN+1];
int main(){
    int n,m,k,i,b,e,x,y,l;
    long long rez;
    scanf("%d%d%d" ,&n,&m,&k);
    for(i=0;i<m;i++){
       scanf("%d%d%d" ,&x,&y,&l);
       Edge a;
       a.nod=y;
       a.l=l;
       G[x].push_back(a);
       a.nod=x;
       G[y].push_back(a);
    }
    for(i=1;i<=n;i++)
      dist[i]=INF;
    for(i=0;i<k;i++){
      scanf("%d" ,&cod[i]);
      dist[cod[i]]=0;
      good[cod[i]]=1;
      vf[cod[i]]=1;
    }
    e=k;
    b=0;
    while(b<e){
        good[cod[b%MAXQ]]=0;
        for(i=0;i<G[cod[b%MAXQ]].size();i++)
          if(dist[G[cod[b%MAXQ]][i].nod]>dist[cod[b%MAXQ]]+G[cod[b%MAXQ]][i].l){
             dist[G[cod[b%MAXQ]][i].nod]=dist[cod[b%MAXQ]]+G[cod[b%MAXQ]][i].l;
             if(good[G[cod[b%MAXQ]][i].nod]==0){
                good[G[cod[b%MAXQ]][i].nod]=1;
                cod[e%MAXQ]=G[cod[b%MAXQ]][i].nod;
                vf[cod[e%MAXQ]]++;
                e++;
             }
          }
          b++;
    }
    rez=INF;
    for(i=1;i<=n;i++)
      if(dist[i]>0&&rez>dist[i])
        rez=dist[i];
    if(rez==INF)
      printf("-1");
    else
      printf("%I64d" ,rez);
    return 0;
}