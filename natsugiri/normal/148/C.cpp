#include<cstdio>
int d[101];
int main(){
  int n,i,a,b,s,p;
  scanf("%d%d%d",&n,&a,&b);
  d[0]=1;
  p=s=1;
  for(i=1;i<n;i++){
    if(b){
      p=s+1;b--;
    }else if(a){
      if(i==1){s++;}
      else{p++;a--;}
    }
    d[i]=p;
    s+=p;
  }
  if(a|b)puts("-1");
  else{
    for(i=0;i<n;i++)printf("%d%c",d[i],n-i-1?' ':'\n');
  }
  return 0;
}