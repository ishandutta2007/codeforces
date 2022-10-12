#include<stdio.h>

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}
int zt(int a,int b){return max(a,b)-min(a,b);}

int main(){
  int t;
  int a[524288];
  scanf("%d",&t);
  while(t>0){
    t--;
    int n;
    scanf("%d",&n);
    int p=-1,q=-1;
    for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
      if(p==-1){p=i;}
      if(q==-1){
        if(a[p]!=a[i]){q=i;}
      }
    }
    if(q==-1){puts("NO");continue;}
    puts("YES");
    printf("%d %d\n",p,q);
    for(int i=1;i<=n;i++){
      if(i==p || i==q){continue;}
      if(a[i]!=a[p]){
        printf("%d %d\n",i,p);
      }
      else{
        printf("%d %d\n",i,q);
      }
    }
  }
  return 0;
}