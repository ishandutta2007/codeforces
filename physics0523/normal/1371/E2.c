#include<stdio.h>

int max(int a,int b){if(a>b){return a;}return b;}

int modp(int x,int p){
  if(x>=0){return x%p;}
  x*=-1;x%=p;
  return (p-x)%p;
}

int main(){
  int n,p;
  int st,fi;
  int a[131072],bk[262144]={0},bas=0,i;
  int fl[131072]={0};
  int res[131072],rc=0;

  scanf("%d%d",&n,&p);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    bas=max(a[i],bas);
  }
  for(i=0;i<n;i++){bk[max(0,a[i]-bas+n)]++;}
  for(i=1;i<262144;i++){bk[i]+=bk[i-1];}

  for(i=0;i<n;i++){
    fl[modp((i+(bas-n))-bk[i],p)]++;
  }

  for(i=0;i<=n;i++){
    if(fl[modp(i+(bas-n),p)]==0){
      res[rc]=i+(bas-n);
      rc++;
    }
    fl[modp((i+(bas-n))-bk[i],p)]--;
    fl[modp(((n+i)+(bas-n))-bk[(n+i)],p)]++;
  }
  printf("%d\n",rc);
  for(i=0;i<rc;i++){
    if(i){printf(" ");}
    printf("%d",res[i]);
  }printf("\n");
  return 0;
}