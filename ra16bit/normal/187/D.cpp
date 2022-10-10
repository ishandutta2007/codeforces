#include <cstdio>
#include <set>
using namespace std;
const int MX=100100;
typedef pair<int,int> pii;
int n,m,gd,rd,t,l,r,i,tm[MX],a[MX],next[MX*2];
long long cur,sum,dop,s[MX],f[MX];
set<pii> st;
set<pii>::iterator it;
void process(pii left, int right) {
  while (!st.empty()) {
    it=st.lower_bound(left);
    if (it!=st.end() && it->first<=right) {
      next[it->second]=i+1;
      st.erase(it);
    } else break;
  }
}
int main() {
  scanf("%d%d%d",&n,&gd,&rd);
  t=gd+rd;
  for (i=0; i<=n; i++) {
    scanf("%d",&a[i]);
    s[i+1]=s[i]+a[i];
  }
  scanf("%d",&m);
  for (i=1; i<=m; i++) {
    scanf("%d",&tm[i]);
    st.insert(make_pair((t-tm[i]%t)%t,n+i));
  }
  for (i=0; i<=n+m; i++) next[i]=n+1;
  for (i=0; i<n; i++) {
    sum+=a[i];
    l=(sum+1)%t;
    r=(sum+rd)%t;
    process(make_pair(l,-1),(r>=l?r:(t-1)));
    if (r<l) process(make_pair(0,-1),r);
    st.insert(make_pair(sum%t,i+1));
  }
  for (i=n; i>=0; i--) if (next[i]==n+1) f[i]=s[n+1]-s[i]; else {
    cur=s[next[i]]-s[i];
    f[i]=f[next[i]]+cur+t-cur%t;
  }
  for (i=1; i<=m; i++) {
    cur=s[next[n+i]]+tm[i];
    if (next[n+i]<=n) dop=t-cur%t; else dop=0;
    printf("%I64d\n",f[next[n+i]]+cur+dop);
  }
  return 0;
}