#include <bits/stdc++.h>
using namespace std;
const int MX=1505,md=998244353;
int n,i,j,a,mx,X,Y,p[MX],rk[MX],cn[MX],cm[MX],x[MX*MX],y[MX*MX];
vector<long long> f[MX];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
const int root = 62;
void ntt(vector<long long> &a) {
  int n = a.size();
  int L = 31 - __builtin_clz(n);
  vector<long long> rt(2, 1);
  for (int k = 2, s = 2; k < n; k *= 2, s++) {
    rt.resize(n);
    long long z[] = {1, pw(root, md >> s)};
    for (int i = k; i < 2 * k; i++) rt[i] = rt[i / 2] * z[i & 1] % md;
  }
  vector<int> rev(n);
  for (int i = 0; i < n; i++) {
    rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k) 
      for (int j = 0; j < k; j++) {
        long long z = rt[j + k] * a[i + j + k] % md, &ai = a[i + j];
        a[i + j + k] = ai - z + (z > ai ? md : 0);
        ai += (ai + z >= md ? z - md : z);
      }
}
vector<long long> mul(const vector<long long> &a, const vector<long long> &b) {
  if (a.empty() || b.empty()) return {};
  int s = a.size() + b.size() - 1;
  int B = 32 - __builtin_clz(s);
  int n = (1 << B);
  int inv = pw(n, md - 2);
  vector<long long> L(a), R(b), out(n);
  L.resize(n); ntt(L);
  R.resize(n); ntt(R);
  for (int i=0; i<n; i++) out[-i & (n - 1)] = L[i] * R[i] % md * inv % md;
  ntt(out);
  return {out.begin(), out.begin() + s};
}
void check(int x) {
//printf("check %d: %d %d\n",x,cn[x],cm[x]);
  if (cm[x]*2==cn[x]*(cn[x]-1)) ++f[x][1];
}
int fs(int x) {
  if (p[x]!=x) p[x]=fs(p[x]);
  return p[x];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<n; j++) {
    scanf("%d",&a);
    if (i<j) {
      x[a]=i;
      y[a]=j;
      mx=max(mx,a);
    }
  }
  for (i=0; i<n; i++) {
    p[i]=i;
    f[i].push_back(0);
    f[i].push_back(1);
    cn[i]=1;
  }
  for (i=1; i<=mx; i++) {
    X=fs(x[i]);
    Y=fs(y[i]);
    if (X!=Y) {
      //printf("union %d %d | %d %d | %I64d %I64d\n",x[i],y[i],X,Y,f[X],f[Y]);
      if (rk[X]<rk[Y]) {
        p[X]=Y;
        //f[Y]=(f[Y]*f[X])%md;
        f[Y]=mul(f[Y],f[X]);
        cn[Y]+=cn[X];
        cm[Y]+=cm[X]+1;
        check(Y);
      } else {
        p[Y]=X;
        //f[X]=(f[X]*f[Y])%md;
        f[X]=mul(f[Y],f[X]);
        if (rk[X]==rk[Y]) ++rk[X];
        cn[X]+=cn[Y];
        cm[X]+=cm[Y]+1;
        check(X);
      }
    } else {
      ++cm[X];
      check(X);
      //printf("no union %d %d | %d (%I64d)\n",x[i],y[i],X,f[X]);
    }
  }
  X=fs(0);
  for (i=1; i<=n; i++) printf("%d ",int(f[X][i]));
  return 0;
}