#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,i,j,x,a,b[22],res;
vector <pair<int,int> > c;
bool r[1111111];
int main() {
  scanf("%d",&n);
  for (i=0; i<20; i++) b[i]=-1;
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    c.clear();
    for (j=0; j<20; j++) {
      if (a&(1<<j)) b[j]=i;
      if (b[j]>=0) c.push_back(make_pair(b[j],1<<j));
    }
    sort(c.rbegin(),c.rend());
    if (a==0) r[0]=true;
    for (j=x=0; j<c.size(); j++) {
      if (j>0 && c[j].first!=c[j-1].first) r[x]=true;
      x|=c[j].second;
    }
    if (c.size()>0) r[x]=true;
  }
  for (i=0; i<(1<<20); i++) if (r[i]) res++;
  printf("%d\n",res);
  return 0;
}