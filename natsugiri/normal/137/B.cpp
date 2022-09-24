#include<cstdio>

int main(){
  int n,a[5001],i,t;
  for(i=0;i<5001;i++)a[i]=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&t);
    a[t]++;
  }
  t=0;
  for(i=1;i<=n;i++){
    if(a[i]==0)t++;
  }

  printf("%d\n",t);
}