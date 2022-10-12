#include<stdio.h>

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}
int zt(int a,int b){return max(a,b)-min(a,b);}

int main(){
  int t;
  scanf("%d",&t);
  int arr[128];
  while(t>0){
    t--;
    int n,res=0;
    scanf("%d",&n);
    int mio=1000000007,mao=0;
    for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
      if(arr[i]==1){mio=min(mio,i);mao=max(mao,i);}
    }
    for(int i=mio;i<=mao;i++){
      if(arr[i]==0){res++;}
    }
    printf("%d\n",res);
  }
  return 0;
}