#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
  int n,m,a[111],i,t;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",a+i);
  m=t=0;
  for(i=0;i<n;i++)m+=a[i];
  sort(a,a+n);
  for(i=0;i<n;i++){
    t+=a[n-1-i];
    m-=a[n-1-i];
    if(m<t)break;
  }
  printf("%d\n",i+1);
  return 0;
}