#include <cstdio>
#include <map>
#include <utility>
#include <vector>
using namespace std;
int n,p,N,i,j,e,a[300010],b,c[300010];
map <pair <int, int>, int> m;
map <pair <int, int>, int>::iterator it;
vector <int> v[300010];
long long s[300010],r[300010];
pair <int, int> z;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&c[i]);
  scanf("%d",&p);
  for (i=0; i<p; i++) {
    scanf("%d%d",&a[i],&b); a[i]--;
    z=make_pair(a[i]%b,b);
    e=m[z];
    if (m[z]==0) m[z]=e=++N;
    v[e].push_back(i);
  }
  for (it=m.begin(); it!=m.end(); it++) {
    j=it->first.second;
    for (i=it->first.first; i<n; i+=j) s[i]=c[i];
    for (i-=j+j; i>=0; i-=j) s[i]+=s[i+j];
    j=it->second;
    for (i=0; i<v[j].size(); i++) r[v[j][i]]=s[a[v[j][i]]];
  }
  for (i=0; i<p; i++) printf("%I64d\n",r[i]);
  return 0;
}