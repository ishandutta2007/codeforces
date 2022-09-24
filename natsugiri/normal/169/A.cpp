#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int h[2000],a,b;
int main(){
  scanf("%d%d%d",&n,&a,&b);
  for(int i=0;i<n;i++)scanf("%d",h+i);
  sort(h,h+n);
  printf("%d\n",h[b]-h[b-1]);
  return 0;
}