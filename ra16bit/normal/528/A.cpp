#include <cstdio>
#include <set>
using namespace std;
int w,h,n,i,j,l,r,x;
long long res;
char s[5];
multiset<int> b[2];
set<int> a[2];
set<int>::iterator it;
int main() {
  scanf("%d%d%d",&w,&h,&n);
  a[0].insert(0); a[0].insert(w); b[0].insert(w);
  a[1].insert(0); a[1].insert(h); b[1].insert(h);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    j=int(s[0]=='H');
    scanf("%d",&x);
    it=a[j].lower_bound(x);
    r=*it; --it; l=*it;
    b[j].erase(b[j].find(r-l));
    b[j].insert(r-x);
    b[j].insert(x-l);
    a[j].insert(x);
    res=*b[0].rbegin();
    res*=*b[1].rbegin();
    printf("%I64d\n",res);
  }
  return 0;
}