#include <bits/stdc++.h>
#define MAXN 1000000
std::vector <int> G[MAXN+1];
bool viz[MAXN+1];
int val[MAXN+1];
int dp[MAXN+1];
std::vector <int> ans;
int root,sum;
void DFS(int nod){
   viz[nod]=1;
   dp[nod]=val[nod];
   for(int i=0;i<G[nod].size();i++){
      int x=G[nod][i];
      if(viz[x]==0){
         DFS(x);
         dp[nod]+=dp[x];
      }
   }
   if(dp[nod]==sum/3&&nod!=root){
      dp[nod]=0;
      ans.push_back(nod);
   }
}
int main(){
    FILE*fi,*fout;
    int i,n,x;
   // fi=fopen("C.in" ,"r");
  //  fout=fopen("C.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    sum=0;
    for(i=1;i<=n;i++){
       fscanf(fi,"%d%d" ,&x,&val[i]);
       sum+=val[i];
       G[x].push_back(i);
       if(x==0)
         root=i;
    }
    if(sum%3)
         fprintf(fout,"-1");
    else{
         DFS(root);
         if(ans.size()>=2)
           fprintf(fout,"%d %d" ,ans[0],ans[1]);
         else
           fprintf(fout,"-1");
    }
 //   fclose(fi);
  //  fclose(fout);
    return 0;
}