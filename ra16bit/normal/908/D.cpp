#include <bits/stdc++.h>
using namespace std;
const int md=1000000007;
int i,j,k,pa,pb,ps;
long long fp[1010][1010],fq[1010][1010];
bool u[1010][1010];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void F(int i, int j) {
  if (u[i][j]) return;
  u[i][j]=true;
  if (j>=k) { fp[i][j]=j; fq[i][j]=1; return; }
  if (i+j>=k) { fp[i][j]=(1LL*(i+j)*pb+pa)%md; fq[i][j]=pb; return; }
  F(i+1,j);
  F(i,i+j);
  fp[i][j]=((pa*fp[i+1][j])%md*fq[i][i+j]+(pb*fp[i][i+j])%md*fq[i+1][j])%md;
  fq[i][j]=((fq[i+1][j]*fq[i][i+j])%md*ps)%md;
}
int main() {
  scanf("%d%d%d",&k,&pa,&pb);
  ps=pa+pb;
  F(1,0);
  printf("%d\n",int((fp[1][0]*pw(fq[1][0],md-2))%md));
  return 0;
}