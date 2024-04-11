#include <bits/stdc++.h>
#define MAXN 150000
std::vector <int> G[MAXN+1];
bool viz[MAXN+1];
int cnt;
void DFS(int nod){
    viz[nod]=1;
    cnt++;
    for(auto x:G[nod])
     if(!viz[x])
        DFS(x);
}
int main(){
   FILE*fi,*fout;
   int i,n,a,b;
   long long m;
  // fi=fopen("B.in" ,"r");
 //  fout=fopen("B.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%I64d" ,&n,&m);
   for(i=1;i<=m;i++){
      fscanf(fi,"%d%d" ,&a,&b);
      G[a].push_back(b);
      G[b].push_back(a);
   }
   for(i=1;i<=n;i++)
    if(!viz[i]){
       cnt=0;
       DFS(i);
       m-=1LL*(cnt-1)*cnt/2;
    }
   if(m!=0)
    fprintf(fout,"NO");
   else
    fprintf(fout,"YES");
  // fclose(fi);
  // fclose(fout);
   return 0;
}