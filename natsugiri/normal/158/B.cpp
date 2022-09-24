#include<cstdio>
int n,i,o,t,h,f,ans,x;
int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x);
    if(x==1)o++;
    if(x==2)t++;
    if(x==3)h++;
    if(x==4)f++;
  }
  if(o<h){
    ans+=o;
    h-=o;
    o=0;
  }else{
    ans+=h;
    o-=h;
    h=0;
  }
  ans+=h;
  ans+=t/2;
  t=t%2;
  if(t){
    ans++;
    o-=2;
  }
  if(o>0){
    ans+=(o+3)/4;
  }
  printf("%d\n",ans+f);
  return 0;
}