#include <cstdio>
#include <vector>
#define MOD (1<<20)
using namespace std;
class Data{
    public :
      long long val;
      long long cost;
};
vector <Data> G[MOD];
int main(){
  // FILE*fi,*fout;
   int q,t,r,i;
   long long sum,v,u,w;
   //fi=fopen("C.in" ,"r");
   //fout=fopen("C.out" ,"w");
   scanf("%d" ,&q);
   while(q>0){
      q--;
      scanf("%d" ,&t);
      if(t==1){
         scanf("%I64d%I64d%I64d" ,&v,&u,&w);
         while(u!=v){
             if(u>v){
                 r=u%MOD;
                 i=0;
                 while(i<G[r].size()&&G[r][i].val!=u)
                    i++;
                 if(i<G[r].size())
                     G[r][i].cost+=w;
                 else{
                     Data x;
                     x.val=u;
                     x.cost=w;
                     G[r].push_back(x);
                 }
                 u/=2;
             }
             else{
                 r=v%MOD;
                 i=0;
                 while(i<G[r].size()&&G[r][i].val!=v)
                    i++;
                 if(i<G[r].size())
                     G[r][i].cost+=w;
                 else{
                     Data x;
                     x.val=v;
                     x.cost=w;
                     G[r].push_back(x);
                 }
                 v/=2;
             }
         }
      }
      else{
          scanf("%I64d%I64d" ,&u,&v);
          sum=0;
          while(u!=v){
              if(u>v){
                 r=u%MOD;
                 i=0;
                 while(i<G[r].size()&&G[r][i].val!=u)
                    i++;
                 if(i<G[r].size())
                    sum+=G[r][i].cost;
                 u/=2;
              }
              else{
                 r=v%MOD;
                 i=0;
                 while(i<G[r].size()&&G[r][i].val!=v)
                    i++;
                 if(i<G[r].size())
                    sum+=G[r][i].cost;
                 v/=2;
              }
          }
          printf("%I64d\n" ,sum);
      }
   }

  // fclose(fi);
 //  fclose(fout);
   return 0;
}