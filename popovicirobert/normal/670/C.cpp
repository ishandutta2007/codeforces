#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 200000
struct stare{
   int v,poz;
};
stare Q[MAXN+1];
bool cmp1(stare a,stare b){
     return (a.v<b.v);
}
int vf[MAXN+1],sav[MAXN+1],B[MAXN+1],C[MAXN+1];
int main(){
   // FILE*fi,*fout;
    int i,j,aux,n,rez,pas,nr,max1,max2,poz,m;
 //   fi=fopen("C.in" ,"r");
    //fout=fopen("C.out" ,"w");
    scanf("%d" ,&n);
    for(i=1;i<=n;i++)
        scanf("%d" ,&Q[i].v);
    sort(Q+1,Q+n+1,cmp1);
    i=1;
    nr=1;
    while(i<=n){
        j=i;
        aux=Q[i].v;
        while(j<=n&&aux==Q[j].v){
           vf[nr]++;
           sav[j]=nr;
           j++;
        }
        i=j;
        nr++;
    }
    scanf("%d" ,&m);
    max1=max2=-1;
    for(i=1;i<=m;i++)
        scanf("%d" ,&B[i]);
    for(i=1;i<=m;i++)
        scanf("%d" ,&C[i]);
    for(i=1;i<=m;i++){
        rez=0;
        for(pas=1<<20;pas;pas>>=1)
           if(rez+pas<=n&&B[i]>=Q[rez+pas].v)
              rez+=pas;
         if(Q[rez].v!=B[i])
             rez=0;
         if(max1<vf[sav[rez]]){
            max1=vf[sav[rez]];
            rez=0;
            for(pas=1<<20;pas;pas>>=1)
              if(rez+pas<=n&&C[i]>=Q[rez+pas].v)
                 rez+=pas;
            if(Q[rez].v!=C[i])
             rez=0;
            max2=vf[sav[rez]];
            poz=i;
         }
         else
            if(max1==vf[sav[rez]]){
              rez=0;
              for(pas=1<<20;pas;pas>>=1)
                if(rez+pas<=n&&C[i]>=Q[rez+pas].v)
                   rez+=pas;
                if(Q[rez].v!=C[i])
                   rez=0;
               if(vf[sav[rez]]>max2){
                  max2=vf[sav[rez]];
                  poz=i;
               }
            }
    }
    printf("%d" ,poz);
   // fclose(fi);
  // fclose(fout);
    return 0;
}