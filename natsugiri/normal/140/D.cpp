#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int n,d[111],i,t,c,p;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",d+i);
  }

  c=p=0;
  t=10;
  sort(d,d+n);
  for(i=0;i<n;i++){
    t+=d[i];
    if(t>720)break;
    if(t>360)p+=t-360;
    c++;
  }
  printf("%d %d\n",c,p);
  return 0;
}