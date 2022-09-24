#include<cstdio>

int main(){
  int n, m;
  scanf("%d%d",&n, &m);
  for (int i=0; i<n; i++) {
    int t=i%m;
    if (m&1) printf("%d\n", (t+1)/2*(t&1?-1:1)+m/2+1);
    else printf("%d\n", (t+1)/2*(t&1?1:-1)+m/2);
  }
  return 0;
}