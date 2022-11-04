#include <bits/stdc++.h>
#define INF 1000000000
#define MAXN 100000
int dp[MAXN+1][3];
int t[MAXN+1];
int ans[MAXN+1];
inline int getmin(int a,int b){
   if(a<b) return a;
   return b;
}
int main(){
    FILE*fi,*fout;
    int i,n,j,m1,m2,m3,p;
  //  fi=fopen("D.in" ,"r");
   // fout=fopen("D.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    for(i=1;i<=n;i++){
        fscanf(fi,"%d" ,&t[i]);
        if(i==1){
             dp[i][0]=20;
             dp[i][1]=50;
             dp[i][2]=120;
             ans[i]=20;
        }
        else{
           dp[i][1]=dp[i][2]=INF;
           dp[i][0]=ans[i-1]+20;
           dp[i][1]=ans[i-1]+50;
           dp[i][2]=ans[i-1]+120;
           for(j=i-1;j>0&&t[i]-t[j]<1440;j--){
              dp[i][0]=getmin(dp[i][0],dp[j][2]);
              if(t[j]+90>t[i]){
                 dp[i][0]=getmin(dp[i][0],dp[j][1]);
                 dp[i][1]=getmin(dp[i][1],dp[j][1]+50);
                 dp[i][2]=getmin(dp[i][2],dp[j][1]+120);
              }
              dp[i][1]=getmin(dp[i][1],dp[j][2]+50);
              dp[i][2]=getmin(dp[i][2],dp[j][2]+120);
           }
        }
        ans[i]=getmin(dp[i][0],getmin(dp[i][1],dp[i][2]));
        fprintf(fout,"%d\n" ,ans[i]-ans[i-1]);
    }
   // fclose(fi);
  //  fclose(fout);
    return 0;
}