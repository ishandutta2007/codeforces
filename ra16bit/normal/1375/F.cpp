#include <bits/stdc++.h>
using namespace std;
const long long inf=10000000000LL;
long long A[5],sum;
int idx,jdx,i,a,b,c;
int main() {
  scanf("%d%d%d",&a,&b,&c);
  A[1]=a;
  A[2]=b;
  A[3]=c;
  puts("First");
  fflush(stdout);
  printf("%I64d\n",inf);
  fflush(stdout);
  scanf("%d",&idx);
  A[idx]+=inf;
  for (i=1; i<4; i++) sum+=A[idx]-A[i];
  printf("%I64d\n",sum);
  fflush(stdout);
  scanf("%d",&jdx);
  A[jdx]+=sum;
  printf("%I64d\n",A[jdx]-A[idx]);
  fflush(stdout);
  scanf("%d",&jdx);
  return 0;
}