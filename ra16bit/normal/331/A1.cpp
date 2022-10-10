#include <cstdio>
#include <map>
#include <vector>
using namespace std;
typedef pair<int,long long> pil;
int n,i,l,r,a[300300];
pil p;
map<int, pil> m;
long long sum,cur,res;
vector<int> v;
int main() {
  res=-1000000000;
  res*=1000000000;
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
	if (m.count(a[i])) {
	  p=m[a[i]];
	  cur=sum-p.second+a[i];
	  if (a[i]<0) cur+=a[i];
	  if (cur>res) {
	    res=cur; l=p.first; r=i;
	  }
	  if (sum<p.second) m[a[i]]=make_pair(i,sum);
	} else m[a[i]]=make_pair(i,sum);
	if (a[i]>=0) sum+=a[i];
  }
  for (i=1; i<=n; i++) if (i<l || i>r || (i>l && i<r && a[i]<0)) v.push_back(i);
  printf("%I64d %d\n",res,int(v.size()));
  for (i=0; i<v.size(); i++) printf("%d%c",v[i],(i+1==v.size())?'\n':' ');
  return 0;
}