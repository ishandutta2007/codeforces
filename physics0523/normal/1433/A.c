#include<stdio.h>
int arr[8]={-1,1,11,111,1111};

int main(){
  int t;
  scanf("%d",&t);
  while(t>0){
    t--;
    int tg,r=0,n;
    scanf("%d",&n);
    for(int i=1;i<=9;i++){
      for(int j=1;j<=4;j++){
        r+=j;
        if(i*arr[j]==n){goto OUTPUT;}
      }
    }
    OUTPUT:
    printf("%d\n",r);
  }

}