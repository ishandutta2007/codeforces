//set many funcs template
//Ver.20190820
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 998244353

long long llmin(long long a,long long b){if(a<b){return a;}return b;}

long long issame(char a,char b){
  if(a=='*'||b=='*'){return 1;}
  if(a==b){return 1;}
  return 0;
}

int main(void){
  long long sl,tl,i,j,c,r=0,cl;
  long long dp[4096]={0},ndp[4096]={0};
  char s[4096],t[4096];
  scanf("%s%s",s,t);
  sl=strlen(s);
  tl=strlen(t);
  cl=sl-tl+1;
  for(i=tl;i<sl;i++){t[i]='*';}
  dp[0]=1;c=0;
  for(i=sl-1;i>=0;i--){
    for(j=0;j<=c;j++){
      if(dp[j]==0){continue;}
      //front-add
      if(issame(s[i],t[j])==1){
        if(j==0){ndp[j+1]+=dp[j]*llmin(cl,c+1);}
        else{ndp[j+1]+=dp[j];}
        ndp[j+1]%=mod;
      }
      //back-add
      if(issame(s[i],t[(sl-c+j)-1])==1){
        ndp[j]+=dp[j];
        ndp[j]%=mod;
      }
    }
    for(j=0;j<=sl;j++){
      dp[j]=ndp[j];
      ndp[j]=0;
      //printf("[%lld]",dp[j]);
    }//printf("\n");
    c++;
  }
  for(i=0;i<=sl;i++){
    r+=dp[i];r%=mod;
  }
  printf("%lld\n",r);
  return 0;
}