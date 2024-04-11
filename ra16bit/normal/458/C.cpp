#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int n,i,j,jj,sum,r,cur,a[100100],b[100100],k[100100];
vector<pii> v[100100];
set<pii> s;
set<pii>::iterator it;
bool cmpk(int i, int j) {
  return v[i].size()>v[j].size();
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&a[i],&b[i]);
    if (a[i]!=0) {
      v[a[i]].push_back(make_pair(b[i],i));
      s.insert(make_pair(b[i],i));
      sum+=b[i];
    } else cur++;
  }
  r=sum;
  for (i=0; i<100010; i++) k[i]=i;
  sort(k,k+100010,cmpk);
  for (jj=0; ; jj++) {
    j=k[jj];
    if (v[j].size()==0) break;
    sort(v[j].rbegin(),v[j].rend());
  }
  for (i=int(s.size())+1; i>0; i--) {
    for (jj=0; ; jj++) {
      j=k[jj];
      if (v[j].size()<i) break;
      it=s.find(v[j][i-1]);
      if (it!=s.end()) s.erase(it); else sum+=v[j][i-1].first;
      cur++;
    }
    while (int(s.size())>0 && int(s.size())+cur>i) {
      it=--s.end();
      sum-=it->first;
      s.erase(it);
    }
    r=min(r,sum);
  }
  printf("%d\n",r);
  return 0;
}