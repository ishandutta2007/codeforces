#include<stdio.h>
#include<stdbool.h>

int main(){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    int res,k,n,m,a[128],fl[128]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&a[i]);fl[a[i]]++;
    }
    k=2;res=0;
    for(int i=0;i<=n;i++){
      if(k>fl[i]){
        res+=i*(k-fl[i]);
        k=fl[i];
      }
      if(k==0){break;}
    }
    printf("%d\n",res);
  }
}