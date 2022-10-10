#include <cstdio>
#include <vector>
using namespace std;
const int md=1000000007,MX=545545;
int T,q,n,m,i,v[200200],t[200200],x[200200],a[200200],b[200200],d[200200],p[200200],c[MX],s[MX];
long long e[MX];
vector<int> g[200200];
void dfs(int i) {
  a[i]=++T;
  for (int j=0; j<g[i].size(); j++) dfs(g[i][j]);
  b[i]=T;
}
long long pw(int a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void push(int i) {
  if (e[i]!=1) {
    e[i*2]=(e[i*2]*e[i])%md;
    e[i*2+1]=(e[i*2+1]*e[i])%md;
    s[i*2]=(s[i*2]*e[i])%md;
    s[i*2+1]=(s[i*2+1]*e[i])%md;
    e[i]=1;
  }
}
int getsum(int i, int L, int R, int l, int r) {
  if (L==l && R==r) return s[i];
  int h=(L+R)/2;
  push(i);
  int res=0;
  if (l<=h) res+=getsum(i*2,L,h,l,min(h,r));
  if (r>h) res+=getsum(i*2+1,h+1,R,max(l,h+1),r);
  return res%md;
}
int get_c(int i, int L, int R, int x, long long cc) {
  cc=(cc*c[i])%md;
  if (L==R) return cc;
  int h=(L+R)/2;
  push(i);
  return (x<=h)?get_c(i*2,L,h,x,cc):get_c(i*2+1,h+1,R,x,cc);
}
int solve(int i) {
  int r=getsum(1,1,n-1,a[i],b[i]);
  if (i>1) r=(r*pw(get_c(1,1,n-1,a[p[i]],1),md-2))%md;
  return r;
}
void addc(int i, int L, int R, int l, int r, long long x) {
  if (L==l && R==r) {
    c[i]=(c[i]*x)%md;
    s[i]=(s[i]*x)%md;
    e[i]=(e[i]*x)%md;
    //printf("c %d %d %d = %d %d\n",i,L,R,c[i],s[i]);
    return;
  }
  int h=(L+R)/2;
  push(i);
  if (l<=h) addc(i*2,L,h,l,min(h,r),x);
  if (r>h) addc(i*2+1,h+1,R,max(l,h+1),r,x);
  s[i]=(s[i*2]+s[i*2+1])%md;
}
int addv(int i, int L, int R, int x, long long cc) {
  cc=(cc*c[i])%md;
  if (L==R) {
    int old=s[i];
    s[i]=(s[i]+cc*v[x])%md;
    old=s[i]-old;
    if (old<0) old+=md;
    //printf("v %d %d %d = %d %d | %I64d %d %d\n",i,L,R,c[i],s[i],cc,old,v[x]);
    return old;
  }
  int h=(L+R)/2;
  push(i);
  int cur=(a[x]<=h)?addv(i*2,L,h,x,cc):addv(i*2+1,h+1,R,x,cc);
  s[i]=(s[i]+cur)%md;
  return cur;
}
int main() {
  scanf("%d%d",&v[1],&q);
  for (n=m=2, i=0; i<q; i++) {
    scanf("%d%d",&t[i],&x[i]);
    if (t[i]==1) {
      scanf("%d",&v[n]);
      g[x[i]].push_back(n);
      p[n++]=x[i];
    }
  }
  dfs(1);
  for (i=0; i<MX; i++) c[i]=e[i]=1;
  addv(1,1,n-1,a[1],1);
  d[1]=1;
  for (i=0; i<q; i++) if (t[i]==1) {
    addv(1,1,n-1,m,1);
    addc(1,1,n-1,a[p[m]],b[p[m]],((d[p[m]]+1LL)*pw(d[p[m]],md-2))%md);
    d[p[m]]++;
    d[m++]=1;
  } else printf("%d\n",solve(x[i]));
  return 0;
}