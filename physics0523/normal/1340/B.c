#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

char dgd[16][8]={
  "1110111",
  "0010010",
  "1011101",
  "1011011",
  "0111010",
  "1101011",
  "1101111",
  "1010010",
  "1111111",
  "1111011"
};

int isps(char ff[8],char tt[8]){
  int i,r=0;
  for(i=0;i<7;i++){
    if(ff[i]=='0'&&tt[i]=='1'){r++;}
    if(ff[i]=='1'&&tt[i]=='0'){return -1;}
  }
  return r;
}

int main(void){
  int i,j,n,m,k,a,b,c,h,w,r=0,l,t;
  int dlt[8];
  char s[2048][8];
  bool dp[2005][14142];
  for(i=0;i<2005;i++){
    for(j=0;j<14142;j++){dp[i][j]=false;}
  }
  scanf("%d%d",&n,&k);
  dp[n][k]=true;
  for(i=0;i<n;i++){
    scanf("%s",s[i]);
  }
  for(i=n-1;i>=0;i--){
    for(j=0;j<=7;j++){dlt[j]=0;}
    for(j=0;j<=9;j++){
      a=isps(s[i],dgd[j]);
      if(a!=-1){dlt[a]=1;}
    }
    for(j=0;j<=7;j++){
      if(dlt[j]==0){continue;}
      for(l=j;l<=k;l++){
        if(dp[i+1][l]){dp[i][l-j]=true;}
      }
    }
  }
  if(dp[0][0]==false){printf("-1\n");return 0;}
  w=0;
  for(i=0;i<n;i++){
    for(j=9;j>=0;j--){
      a=isps(s[i],dgd[j]);
      //printf("[%d %d %d %d]\n",i,j,w,a);
      if(a==-1){continue;}
      if((w+a)>k){continue;}
      if(dp[i+1][w+a]){
        printf("%d",j);
        w+=a;
        break;
      }
    }
  }printf("\n");
  return 0;
}