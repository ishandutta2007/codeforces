#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
const int md=1000000007;
int n,m,i,j,e,cur,a[200200],s[200200],k[200200],r[200200];
vector<pii> v[200200];
pii b[200200];
map<int,int> w;
map<int,int>::iterator it;
long long pw(int a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (a*pw(a,b-1))%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void add(int i, long long v) {
  for (; i<=n; i=(i<<1)-(i&(i-1))) s[i]=(s[i]*v)%md;
}
int mul(int i) {
  long long r=1;
  for (; i>0; i&=i-1) r=(r*s[i])%md;
  return r;
}
void mno(int i, int j) {
  int c=((j-1)*pw(j,md-2))%md;
  if (w.count(j)) v[w[j]].push_back(make_pair(c,i)); else add(i,c);
  w[j]=i;
}
bool cmp(int i, int j) { return b[i]<b[j]; }
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) s[i]=1;
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    add(i,cur=a[i]);
    for (j=2; j*j<=cur; j++) if (cur%j==0) {
      mno(i,j);
      for (; cur%j==0; cur/=j);
    }
    if (cur>1) mno(i,cur);
  }
  for (it=w.begin(); it!=w.end(); it++) v[it->second].push_back(make_pair(((it->first-1)*pw(it->first,md-2))%md,0));
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&b[i].first,&b[i].second);
    k[i]=i;
  }
  sort(k,k+m,cmp);
  for (i=1, j=0; i<=n && j<m; i++) {
    for (; j<m && b[k[j]].first==i; j++) r[k[j]]=mul(b[k[j]].second);
    add(i,pw(a[i],md-2));
    for (e=0; e<v[i].size(); e++) {
      add(i,pw(v[i][e].first,md-2));
      if (v[i][e].second>0) add(v[i][e].second,v[i][e].first);
    }
  }
  for (i=0; i<m; i++) printf("%d\n",r[i]);
  return 0;
}