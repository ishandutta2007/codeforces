#include<cstdio>
#include<algorithm>
using namespace std;

int calc(int n,int m){
  return (n+2)/3*m;
}

int main(){
  int n,m;
  int ans=0;
  scanf("%d%d",&n,&m);
  
  if(m<n)swap(n,m);

  if(n==1){
    ans=m;
  }else if(n==2){
    ans=m/4*4;
    ans+=m%4*2;
    if(m%4==3)ans-=2;
  }else{
    ans=max(calc(n,m),calc(m,n));
    ans=max(ans,(n*m+1)/2);
  }
    
  printf("%d\n",ans);
  return 0;
}