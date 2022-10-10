#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int n,i;
vector<int> b,r;
pair<pii,int> a[200200];
bool ok[200200];
bool cross(pii x, pii y, pii z, bool w=false) {
  long long fi=z.first*y.second;
  fi*=x.first-y.first;
  fi*=x.second-z.second;
  long long la=y.first*z.second;
  la*=x.first-z.first;
  la*=x.second-y.second;
  return fi<la;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&a[i].first.first,&a[i].first.second);
    a[i].first.second=-a[i].first.second;
    a[i].second=i;
  }
  sort(a,a+n);
  reverse(a,a+n);
  b.push_back(0);
  a[0].first.second=-a[0].first.second;
  for (i=1; i<n; i++) {
    a[i].first.second=-a[i].first.second;
    while (b.size()>0 && a[b.back()].first.first==a[i].first.first && a[b.back()].first.second<=a[i].first.second) b.pop_back();
    if (b.size()>0 && a[b.back()].first.second>=a[i].first.second) continue;
    while (b.size()>1 && cross(a[b[int(b.size())-2]].first,a[b.back()].first,a[i].first)) b.pop_back();
    b.push_back(i);
  }
  for (i=0; i<b.size(); i++) ok[b[i]]=true;
  for (i=1; i<n; i++) if (a[i].first==a[i-1].first && ok[i-1]) ok[i]=true;
  for (i=n-1; i>=0; i--) {
    if (i+1<n && a[i].first==a[i+1].first && ok[i+1]) ok[i]=true;
    if (ok[i]) r.push_back(a[i].second);
  }
  sort(r.begin(),r.end());
  for (i=0; i<r.size(); i++) printf("%d%c",r[i]+1,(i+1==r.size())?'\n':' ');
  return 0;
}