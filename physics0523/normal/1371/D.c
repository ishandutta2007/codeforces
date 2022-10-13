#include<stdio.h>

int main(){
  int n,k,t,i,j,p,q;
  char res[305][305];
  scanf("%d",&t);
  while(t>0){
    t--;
    scanf("%d%d",&n,&k);
    if(k%n==0){printf("0\n");}
    else{printf("2\n");}
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        res[i][j]='0';
      }
      res[i][n]=0;
    }
    p=0;q=0;
    while(k>0){
      k--;
      res[p][q]='1';
      p++;q++;q%=n;
      if(p==n){
        p=0;q++;q%=n;
      }
    }
    for(i=0;i<n;i++){
      printf("%s\n",res[i]);
    }
  }
}