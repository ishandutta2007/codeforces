#include <cstdio>
#define MAXN 1000
int dp[MAXN+1][3];
int v[MAXN+1];
inline int getmin(int a,int b){
    if(a<b)
      return a;
    return b;
}
int main(){
  // FILE*fi,*fout;
   int n,i;
  // fi=fopen("C.in" ,"r");
 //  fout=fopen("C.out" ,"w");
   scanf("%d" ,&n);
   for(i=1;i<=n;i++)
     scanf("%d" ,&v[i]);
   dp[1][0]=1;
   if(v[1]%2==1)
     dp[1][1]=0;
   else
     dp[1][1]=n;
   if(v[1]>=2)
     dp[1][2]=0;
   else
     dp[1][2]=n;
   for(i=2;i<=n;i++){
      dp[i][0]=getmin(dp[i-1][0],getmin(dp[i-1][1],dp[i-1][2]))+1;
      if(v[i]%2==1)
        dp[i][1]=getmin(dp[i-1][0],dp[i-1][2]);
      else
        dp[i][1]=n;
      if(v[i]>=2)
        dp[i][2]=getmin(dp[i-1][0],dp[i-1][1]);
      else
        dp[i][2]=n;
   }
   printf("%d" ,getmin(dp[n][0],getmin(dp[n][1],dp[n][2])));
  // fclose(fi);
  // fclose(fout);
   return 0;
}