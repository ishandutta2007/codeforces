#include<stdio.h>

void aout(long long a[32][32],long long n){
  long long i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(j!=0){printf(" ");}
      printf("%lld",a[i][j]);
    }printf("\n");
  }
  fflush(stdout);
}

int main(){
  long long n,q,a[32][32],i,j,v;
  long long x,y;
  scanf("%lld",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i%2==0){a[i][j]=0;}
      else{a[i][j]=(1ll<<(i+j));}
    }
  }
  aout(a,n);
  scanf("%lld",&q);
  while(q>0){
    q--;
    scanf("%lld",&v);
    x=1;y=1;
    printf("1 1");
    for(i=1;i<=2*(n-1);i++){
      if((v&(1ll<<(i-1)))==0 && (v&(1ll<<i))!=0){x++;}
      else if((v&(1ll<<(i-1)))!=0 && (v&(1ll<<i))==0){x++;}
      else{y++;}
      printf(" %lld %lld",x,y);
    }
    printf("\n");
    fflush(stdout);
  }
}