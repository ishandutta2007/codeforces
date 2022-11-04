#include <bits/stdc++.h>
inline bool good(char a){
   if(isalpha(a)||isdigit(a))
     return 1;
   return 0;
}
#define MAXN 400000
std::vector <char> mat[MAXN+1];
std::vector <int> LVL[MAXN+1];
int dp[MAXN+1];
bool viz[MAXN+1];
int n,j;
int ans;
void DFS(int nod,int lvl){
   if(lvl>ans)
     ans=lvl;
   LVL[lvl].push_back(nod);
   viz[nod]=1;
   j=nod+1;
   while(dp[nod]>0){
      DFS(j,lvl+1);
      dp[nod]--;
   }
}
int main(){
    FILE*fi,*fout;
    int i,p;
    char a;
   // fi=fopen("E.in" ,"r");
  //  fout=fopen("E.out" ,"w");
    fi=stdin;
    fout=stdout;
    a=fgetc(fi);
    n=0;
    while(good(a)||a==','){
        if(isalpha(a)){
            n++;
            while(isalpha(a)){
                mat[n].push_back(a);
                a=fgetc(fi);
            }
            a=fgetc(fi);
            while(isdigit(a)){
                dp[n]=dp[n]*10+a-'0';
                a=fgetc(fi);
            }
        }
        else
            a=fgetc(fi);
    }
    ans=0;
    for(i=1;i<=n;i++)
      if(viz[i]==0)
        DFS(i,1);
    fprintf(fout,"%d\n" ,ans);
    for(i=1;i<=ans;i++){
        for(j=0;j<LVL[i].size();j++){
            for(p=0;p<mat[LVL[i][j]].size();p++)
             fprintf(fout,"%c" ,mat[LVL[i][j]][p]);
             if(j<LVL[i].size()-1)
               fprintf(fout," ");
        }
        fprintf(fout,"\n");
    }
  //  fclose(fi);
   // fclose(fout);
    return 0;
}