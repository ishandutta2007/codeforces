#include<cstdio>

int n,x;


int main(){
  scanf("%d%d",&n,&x);
  int h,l,t;
  h=l=t=0;

  for(int i=0;i<n;i++){
    int m;
    scanf("%d",&m);
    if(m<x)l++;
    if(m>x)h++;
    if(m==x)t++;
  }
  for(int cnt=0;;cnt++){
    if(l<(n+1)/2 && (n+1)/2<=l+t){
      printf("%d\n",cnt);
      return 0;
    }
    t++;n++;
  }
  return 0;
}