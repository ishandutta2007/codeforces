#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,k,p,i,j,x,a[1010],b[1010];
long long cur,ca[1000100],cb[1000100],r=1000000000;
priority_queue<long long> qa,qb;
int main() {
  r*=-r;
  scanf("%d%d%d%d",&n,&m,&k,&p);
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    scanf("%d",&x);
    a[i]+=x;
    b[j]+=x;
  }
  for (i=0; i<n; i++) qa.push(a[i]);
  for (j=0; j<m; j++) qb.push(b[j]);
  for (i=1; i<=k; i++) {
    cur=qa.top(); qa.pop();
    qa.push(cur-p*m);
    ca[i]=ca[i-1]+cur;
    cur=qb.top(); qb.pop();
    qb.push(cur-p*n);
    cb[i]=cb[i-1]+cur;
  }
  for (i=0; i<=k; i++) r=max(r,ca[i]+cb[k-i]-((long long)i)*(k-i)*p);
  printf("%I64d\n",r);
  return 0;
}