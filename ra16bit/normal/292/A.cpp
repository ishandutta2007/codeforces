#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,t,c,l,r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&t,&c);
	l=max(t,l)+c;
	r=max(l-t,r);
  }
  printf("%d %d\n",l,r);
  return 0;
}