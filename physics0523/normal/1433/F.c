#include<stdio.h>

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}

int main(){
  int n,m,k;
  int dp[80],ndp[80];
  int pdp[80][80];
  scanf("%d%d%d",&n,&m,&k);
  for(int i=0;i<k;i++){
    dp[i]=-1000000007;
    ndp[i]=-1000000007;
  }
  dp[0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<80;j++){
      for(int jj=0;jj<80;jj++){
        pdp[j][jj]=-1000000007;
      }
    }
    pdp[0][0]=0;
    for(int j=0;j<m;j++){
      int a;
      scanf("%d",&a);
      for(int cnt=j;cnt>=0;cnt--){
        for(int val=0;val<k;val++){
          if(pdp[cnt][val]<0){continue;}
          pdp[cnt+1][(val+a)%k]=max(pdp[cnt][val]+(val+a)/k,pdp[cnt+1][(val+a)%k]);
        }
      }
    }
    for(int cnt=0;cnt<=(m/2);cnt++){
      for(int val=0;val<k;val++){
        for(int cv=0;cv<k;cv++){
          ndp[(cv+val)%k]=max(dp[cv]+pdp[cnt][val]+(cv+val)/k,ndp[(cv+val)%k]);
        }
      }
    }
    for(int j=0;j<k;j++){
      dp[j]=ndp[j];
      ndp[j]=-1000000007;
    }
  }
  printf("%d\n",k*dp[0]);
  return 0;
}