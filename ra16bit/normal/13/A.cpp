#include <cstdio>
using namespace std;
int n,i,j,ii;
int nod(int a, int b) { return (b==0)?a:nod(b,a%b); }
int main() {
  scanf("%d",&n);
  for (ii=2; ii<n; ii++) for (i=n; i>0; i/=ii) j+=i%ii;
  n-=2; ii=nod(j,n);
  printf("%d/%d\n",j/ii,n/ii);
  return 0;
}