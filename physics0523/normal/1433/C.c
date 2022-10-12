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
    a[0]=1000000007;
    a[n+1]=1000000007;
    int pm=-1;
    for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
      pm=max(pm,a[i]);
    }
    int fl=1;
    for(int i=1;i<=n;i++){
      if(a[i]!=pm){continue;}
      if(a[i-1]<a[i] || a[i]>a[i+1]){fl=0;printf("%d\n",i);break;}
    }
    if(fl){puts("-1");}
  }
  return 0;
}