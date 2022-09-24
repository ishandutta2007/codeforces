#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
  int n,a[12],i;
  scanf("%d",&n);
  for(i=0;i<12;i++)scanf("%d",a+i);
  sort(a,a+12);
  if(n<1){puts("0");return 0;}
  for(i=11;i>=0;i--){
    n-=a[i];
    if(n<1){printf("%d\n",12-i);return 0;}
  }
  puts("-1");
  return 0;
}