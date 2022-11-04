#include <bits/stdc++.h>
#define MAXN 200000
std::vector <int> G[MAXN+1];
bool viz[MAXN+1];
int v[MAXN+1];
int vf[MAXN+1];
int f[MAXN+1];
int cnt,max,ind;
void DFS(int nod){
   viz[nod]=1;
   if(f[v[nod]]!=ind){
      vf[v[nod]]=0;
      f[v[nod]]=ind;
   }
   vf[v[nod]]++;
   if(vf[v[nod]]>max)
      max=vf[v[nod]];
   cnt++;
   for(int i=0;i<G[nod].size();i++){
    int x=G[nod][i];
    if(viz[x]==0)
      DFS(x);
   }
}
int main(){
    FILE*fi,*fout;
    int i,n,m,k,a,b,ans;
  //  fi=fopen("G.in" ,"r");
  //  fout=fopen("G.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d%d" ,&n,&m,&k);
    for(i=1;i<=n;i++)
      fscanf(fi,"%d" ,&v[i]);
    for(i=1;i<=m;i++){
      fscanf(fi,"%d%d" ,&a,&b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    ans=0;
    ind=1;
    for(i=1;i<=n;i++)
      if(viz[i]==0){
         cnt=0;
         max=0;
         DFS(i);
         ans+=cnt-max;
         ind++;
      }
    fprintf(fout,"%d" ,ans);
 //   fclose(fi);
  //  fclose(fout);
    return 0;
}