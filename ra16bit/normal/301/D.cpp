#include <cstdio>
#include <vector>
using namespace std;
int i,j,k,x,n,q,m[200200],s[200200],r[200200];
vector<int> a[200200];
vector<pair<int,int> > b[200200];
void add(int x, int y) {
  if (x>y) swap(x,y);
  if (x!=0) a[x].push_back(y);
}
int sum(int i) {
  int r=0;
  for (; i>0; i&=i-1) r+=s[i];
  return r;
}
int main() {
  scanf("%d%d",&n,&q);
  for (i=1; i<=n; i++) {
    scanf("%d",&x);
	m[x]=i;
  }
  for (i=1; i<=n; i++) {
    x=m[i];
    for (j=1; j*j<=i; j++) if (i%j==0) {
	  add(x,m[j]);
	  if (i/j>j) add(x,m[i/j]);
    }
  }
  for (i=0; i<q; i++) {
    scanf("%d%d",&x,&j);
	b[x].push_back(make_pair(j,i));
  }
  for (i=n; i>0; i--) {
    for (j=0; j<a[i].size(); j++) for (k=a[i][j]; k<=n; k=(k<<1)-(k&(k-1))) s[k]++;
    for (j=0; j<b[i].size(); j++) r[b[i][j].second]=sum(b[i][j].first)-sum(i-1);
  }
  for (i=0; i<q; i++) printf("%d\n",r[i]);
  return 0;
}