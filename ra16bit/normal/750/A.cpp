#include <bits/stdc++.h>
using namespace std;
int n,m,i,cur;
int main() {
  scanf("%d%d",&n,&m);
  for (cur=i=0; i<n; i++) {
    cur+=(i+1)*5;
	if (cur+m>240) break;
  }
  printf("%d\n",i);
  return 0;
}