#include <bits/stdc++.h>
#define MAXN 200000
int index[MAXN+1],cost[MAXN+1];
int poz[MAXN+1];
bool viz[MAXN+1];
std::vector <int> G[MAXN+1];
inline int cauta(int p,int k){
   int i,rez,pas,con;
   con=0;
   for(i=1;i<=k;i++){
       rez=-1;
       for(pas=1<<17;pas;pas>>=1)
        if(rez+pas<G[poz[i]].size()&&G[poz[i]][rez+pas]<p)
         rez+=pas;
       rez++;
       con+=(G[poz[i]].size()-rez);
   }
   return con;
}
int main(){
    FILE*fi,*fout;
    int i,n,k,q,rez,pas,x;
  //  fi=fopen("D.in" ,"r");
   // fout=fopen("D.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    for(i=1;i<=n;i++){
      fscanf(fi,"%d%d" ,&index[i],&cost[i]);
      G[index[i]].push_back(i);
    }
    fscanf(fi,"%d" ,&q);
    while(q>0){
        q--;
        fscanf(fi,"%d" ,&k);
        for(i=1;i<=k;i++)
            fscanf(fi,"%d" ,&poz[i]);
        rez=0;
        for(pas=1<<17;pas;pas>>=1)
             if(rez+pas<=n&&cauta(rez+pas,k)!=n-(rez+pas)+1)
               rez+=pas;
        if(rez==0)
            fprintf(fout,"0 0\n");
        else{
           poz[++k]=index[rez];
           rez=0;
           for(pas=1<<17;pas;pas>>=1)
             if(rez+pas<=n&&cauta(rez+pas,k)!=n-(rez+pas)+1)
               rez+=pas;
           x=rez;
           rez=-1;
           for(pas=1<<17;pas;pas>>=1)
             if(rez+pas<G[poz[k]].size()&&G[poz[k]][rez+pas]<x)
               rez+=pas;
           rez++;
           rez=G[poz[k]][rez];
           fprintf(fout,"%d %d\n" ,index[rez],cost[rez]);
        }
    }
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}