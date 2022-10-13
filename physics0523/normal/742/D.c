#include<stdio.h>

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}

typedef struct{
    int par;
    int dep;
    int size;
}node;

node uft[1024];

void resuf(){
    int i;
    for(i=0;i<1024;i++){
        uft[i].par=i;uft[i].dep=0;uft[i].size=1;
    }
    return;
}

int find(int x){
    if(uft[x].par==x){return x;}
    else{uft[x].par=find(uft[x].par);return uft[x].par;}
}

void uni(int x,int y){
    int xp,yp;
    xp=find(x);yp=find(y);
    if(xp==yp){return;}
    if(uft[xp].dep>uft[yp].dep){
        uft[yp].par=xp;
        uft[xp].size+=uft[yp].size;
    }
    else{
        uft[xp].par=yp;
        uft[yp].size+=uft[xp].size;
        if(uft[xp].dep==uft[yp].dep){uft[yp].dep++;}
    }
    return;
}

int size(int x){
    x=find(x);
    return uft[x].size;
}

int main(){
  resuf();
  int n,m,lim;
  int w[1024],b[1024];
  scanf("%d%d%d",&n,&m,&lim);
  for(int i=1;i<=n;i++){scanf("%d",&w[i]);}
  for(int i=1;i<=n;i++){scanf("%d",&b[i]);}
  for(int i=0;i<m;i++){
    int p,q;
    scanf("%d%d",&p,&q);
    uni(p,q);
  }
  int dp[1024]={0};
  int mm[1024],mc;
  for(int i=1;i<=n;i++){
    mc=0;
    int sw=0,sb=0;
    for(int j=1;j<=n;j++){
      if(find(j)!=i){continue;}
      mm[mc]=j;mc++;
      sw+=w[j];
      sb+=b[j];
    }
    if(mc==0){continue;}
    for(int j=lim;j>=0;j--){
      for(int k=0;k<mc;k++){
        if(j+w[mm[k]]<=lim){
          dp[j+w[mm[k]]]=max(dp[j]+b[mm[k]],dp[j+w[mm[k]]]);
        }
      }
      if(j+sw<=lim){dp[j+sw]=max(dp[j+sw],dp[j]+sb);}
    }
  }
  printf("%d\n",dp[lim]);
  return 0;
}