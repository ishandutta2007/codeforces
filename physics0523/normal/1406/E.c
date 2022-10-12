#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int n;

int qA(int x){
  if(x>n){return 0;}
  printf("A %d\n",x);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  return res;
}

int qB(int x){
  if(x>n){return 0;}
  printf("B %d\n",x);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  return res;
}

void qC(int x){
  if(x>n){return 0;}
  printf("C %d\n",x);
  fflush(stdout);
}

bool *plfl;

long long lim=200000;
void sieve_of_erat(){
  plfl=malloc(sizeof(bool)*(lim+5));
  long long i,j;
  for(i=0;i<lim+5;i++){plfl[i]=true;}
  plfl[0]=false;
  plfl[1]=false;
  for(i=2;i<lim;i++){
    if(!plfl[i]){continue;}
    for(j=2*i;j<lim;j+=i){
      plfl[j]=false;
    }
  }
  return;
}

int fl[131072];

void del(int x){
  for(int i=x;i<=n;i+=x){fl[i]=0;}
}
int find(int x){
  int res=0;
  for(int i=x;i<=n;i+=x){res+=fl[i];}
  return res;
}

int main(){
  sieve_of_erat();
  int pll[9600],c=0,k=1;
  while(c<9600){
    if(plfl[k]){pll[c]=k;c++;}
    k++;
  }
  scanf("%d",&n);
  for(int i=1;i<=n;i++){fl[i]=1;}

  int res=1;

  for(int i=0;i<96;i++){
    if(res==1){
      for(int j=0;j<100;j++){
        qB(pll[i*100+j]);
        del(pll[i*100+j]);
      }
      if(find(1)==qA(1)){continue;}
      for(int j=0;j<100;j++){
        if(qA(pll[i*100+j])==1){res*=pll[i*100+j];}
      }
    }
    else{
      for(int j=0;j<100;j++){
        if(find(pll[i*100+j])!=qA(pll[i*100+j])){res*=pll[i*100+j];}
      }
    }
  }

  for(int i=0;i<9600;i++){
    if(pll[i]<1000 && res%pll[i]==0){
      int pf=pll[i];
      qB(pll[i]);
      while(1){
        pf*=pll[i];
        if(qA(pf)==0){break;}
        res*=pll[i];
      }
    }
  }

  qC(res);
  return 0;
}