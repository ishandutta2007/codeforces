#include <bits/stdc++.h>
using namespace std;
const int md=1000000007;
struct Frac {
  long long p,q;
  Frac& operator+=(const Frac& f) {
    if (q==0) q=1;
    p=(p*f.q+q*f.p)%md;
    q=(q*f.q)%md;
    return *this;
  }
} d,f;
int n,i,ii,i1,j,e,mask,p[7][7];
map<set<int>,Frac> st[2];
set<int> cur;
int pw(long long a, int b) {
  if (b==0) return 1;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d",&p[i][j]);
  cur.insert(0);
  st[0][cur]={1,1};
  for (i=0; i<n; i++) {
    ii=i&1; i1=1-ii;
    st[i1].clear();
    for (mask=0; mask<(1<<n); mask++) {
      d.p=d.q=1;
      for (j=0; j<n; j++) {
        d.p=(d.p*(((mask>>j)&1)?p[i][j]:(100-p[i][j])))%md;
        d.q=(d.q*100)%md;
      }
      for (const auto& it: st[ii]) {
        cur.clear();
        for (e=0; e<n; e++) if ((mask>>e)&1) for (const auto& jt: it.first)
          if (((jt>>e)&1)==0) cur.insert(jt^(1<<e));
        f.p=(d.p*it.second.p)%md;
        f.q=(d.q*it.second.q)%md;
        st[i1][cur]+=f;
      }
    }
  }
  for (const auto& it: st[n&1]) if (it.first.size()==1 && *(it.first.begin())==(1<<n)-1) {
    printf("%d\n",int((it.second.p*pw(it.second.q,md-2))%md));
    return 0;
  }
  puts("0");
  return 0;
}