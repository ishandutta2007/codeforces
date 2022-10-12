#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    int n,k;
    scanf("%d%d",&n,&k);
    int bk[64][2]={0},a;
    for(int i=0;i<n;i++){
      scanf("%d",&a);
      bk[a][0]++;
    }
    for(int i=0;i<n;i++){
      scanf("%d",&a);
      bk[a][1]++;
    }
    int res=0;
    for(int i=30;i>=1;i--){
      while(n>0 && k>0 && bk[i][1]>0){
        res+=i;
        n--;k--;bk[i][1]--;
      }
      while(n>0 && bk[i][0]>0){
        res+=i;
        n--;bk[i][0]--;
      }
    }
    printf("%d\n",res);
  }
  return 0;
}