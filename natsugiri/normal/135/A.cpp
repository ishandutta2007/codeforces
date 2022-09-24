#include<cstdio>
#include<algorithm>
using namespace std;

int a[100000];

int main(){
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",a+i);
  sort(a,a+n);
  if(a[n-1]==1)a[n-1]=2;
  else a[n-1]=1;
  sort(a,a+n);
  for(i=0;i<n;i++)printf("%s%d",i?" ":"",a[i]);
  puts("");
  return 0;
}