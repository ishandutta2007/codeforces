#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000
int v[MAXN],pmax[MAXN],pmin[MAXN];
int cauta(int l,int n){
    int min=10,i,bmin,bmax,emin,emax;
    emin=emax=-1;
    for(i=0;i<l;i++){
        while(emin>=0&&v[pmin[emin]]>=v[i])
           emin--;
        pmin[++emin]=i;
        while(emax>=0&&v[pmax[emax]]<=v[i])
          emax--;
        pmax[++emax]=i;
    }
    if(v[pmax[0]]-v[pmin[0]]<min)
       min=v[pmax[0]]-v[pmin[0]];
    bmin=bmax=0;
    for(i=l;i<n;i++){
        if(i-l==pmin[bmin])
          bmin++;
        if(i-l==pmax[bmax])
          bmax++;
        while(emin>=bmin&&v[pmin[emin]]>=v[i])
           emin--;
        pmin[++emin]=i;
        while(emax>=bmax&&v[pmax[emax]]<=v[i])
          emax--;
        pmax[++emax]=i;
        if(v[pmax[bmax]]-v[pmin[bmin]]<min)
            min=v[pmax[bmax]]-v[pmin[bmin]];
    }
    if(min>1)
      return 0;
    return 1;
}
int main(){
   // FILE*fi,*fout;
    int rez,pas,i,n;
   // fi=fopen("B.in" ,"r");
   // fout=fopen("B.out" ,"w");
    scanf("%d" ,&n);
    for(i=0;i<n;i++)
       scanf("%d" ,&v[i]);
    rez=0;
    for(pas=1<<17;pas;pas>>=1)
       if(rez+pas<=n&&cauta(rez+pas,n)==1)
          rez+=pas;
   printf("%d" ,rez);
    //fclose(fi);
    //fclose(fout);
    return 0;
}