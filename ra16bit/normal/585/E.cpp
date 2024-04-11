#include <cstdio>
#include <vector>
using namespace std;
const int MX=10000100,md=1000000007;
int n,x,i,j,cnt,r,a[MX],c[MX],d[MX],pw2[500500];
vector<int> v[500500],w[500500],vv;
void rec(int l, int z, int s) {
  if (l==v[z].size()) {
    c[s]++;
    return;
  }
  for (int i=0; i<=w[z][l]; i++) {
    rec(l+1,z,s);
    s*=v[z][l];
  }
}
void rec2(int l, int z, int s) {
  if (l==vv.size()) {
    if (s!=1) {
      if (z) cnt=(cnt+md-c[s])%md; else cnt=(cnt+c[s])%md;
    }
    return;
  }
  rec2(l+1,z,s);
  rec2(l+1,z^1,s*vv[l]);
}
int main() {
  scanf("%d",&n);
  for (pw2[0]=i=1; i<=n; i++) pw2[i]=(pw2[i-1]*2)%md;
  for (i=2; i<MX; i++) if (a[i]==0) for (j=i; j<MX; j+=i) a[j]=i;
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    for (j=x; j>1; j/=a[j]) if (v[i].empty() || a[j]!=v[i].back()) {
      v[i].push_back(a[j]);
      w[i].push_back(1);
    } else w[i][w[i].size()-1]++;
    rec(0,i,1);
  }
  for (i=MX-1; i>=2; i--) if (c[i]) {
    d[i]=pw2[c[i]]-1;
    for (j=i+i; j<MX; j+=i) if (d[j]) d[i]=(d[i]+md-d[j])%md;
    vv.clear();
    for (j=i; j>1; j/=a[j]) if (vv.empty() || a[j]!=vv.back()) vv.push_back(a[j]);
    cnt=n;
    rec2(0,0,1);
    r=(r+1LL*cnt*d[i])%md;
  }
  printf("%d\n",r);
  return 0;
}