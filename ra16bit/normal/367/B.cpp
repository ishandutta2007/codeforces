#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int M,n,m,p,i,j,k,cur,nat,cnt,a[200200],b[200200];
map<int,int> c,d;
vector<int> ans;
int main() {
  scanf("%d%d%d",&n,&m,&p);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<m; i++) { scanf("%d",&b[i]); c[b[i]]++; }
  M=c.size();
  for (i=0; i<p; i++) if (i+(m-1LL)*p<n) {
    d.clear(); cnt=0;
    for (j=k=i; j+(m-1LL)*p<n; j+=p) {
      for (; k<j+m*p; k+=p) {
        cur=++d[a[k]];
        nat=c[a[k]];
        if (cur==nat) cnt++;
        if (cur-1==nat) cnt--;
      }
      if (cnt==M) ans.push_back(j);
      cur=--d[a[j]];
      nat=c[a[j]];
      if (cur==nat) cnt++;
      if (cur+1==nat) cnt--;
    }
  }
  sort(ans.begin(),ans.end());
  printf("%d\n",int(ans.size()));
  for (i=0; i<ans.size(); i++) printf("%d%c",ans[i]+1,(i+1==ans.size())?'\n':' ');
  return 0;
}