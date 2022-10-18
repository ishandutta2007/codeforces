#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"

const int maxn = 1 << 19;
const ld eps = 1e-2;
const ld PI = acos((ld)-1);
struct pnt {
  ld x, y;
  pnt() {    
  }
  pnt(ld x, ld y):x(x), y(y) {
  }
  inline pnt operator * (const pnt& a) {
    return pnt(x * a.x - y * a.y, x * a.y + y * a.x);
  }
  inline pnt operator + (const pnt& a){
    return pnt(x + a.x, y + a.y);
  }
  inline void operator += (const pnt& a){
    x += a.x, y += a.y;
  }
  inline pnt operator - (const pnt& a){
    return pnt(x - a.x, y - a.y);
  }
  inline pnt operator !(){
    return pnt(x, -y);
  }
  inline pnt operator * (ld c){
    return pnt(x * c, y * c);
  }
  void operator *= (const pnt& a) {
    tie(x, y) = mp(x * a.x - y * a.y, x * a.y + y * a.x);  
  }
  inline void operator /=(ld c) {
    x /= c;
    y /= c;
  }
  inline pnt operator / (ld c) const {
    return pnt(x / c, y / c);
  }
  // * i
  inline pnt rev() const {
    return pnt(-y, x);  
  }
};
pnt a[maxn];
pnt c[maxn];
pnt pp[maxn];
int p[maxn];
void fft_forv(int n,pnt* a,int dr){
  int nn=1;
  while (nn<n){
    
    if  (nn == 1) {
      for (int i = 0; i < n; i += 2) {
          a[i] += a[i + 1];
          a[i + 1] = a[i] - a[i + 1] * 2;        
      }
      nn *= 2;
      continue;
    }
    /*
    if  (nn == 2) {
//      printf("%.5f %.5f\n", pp[2].x, pp[2].y);
      for (int i = 0; i < n; i += 4) {
          pnt a0 = a[i] + a[i + 1] + a[i + 2] + a[i + 3];
          pnt a1 = a[i] + a[i + 1].rev() - a[i + 2] - a[i + 3].rev();
          pnt a2 = a[i] - a[i + 1] + a[i + 2] - a[i + 3];
          a[i + 3] = a[i] - a[i + 1].rev() - a[i + 2] + a[i + 3].rev();
          a[i + 2] = a2;
          a[i + 1] = a1;
          a[i] = a0;
          if  (dr == -1) {
            swap(a[i + 1], a[i + 3]);
          }
      }
      nn *= 2;
      continue;
    }
    */
    pnt w=pp[nn];
    if (dr==-1)
      w=!w;
    pnt tk=pnt(1,0);
    for (int j=0;j<nn;j++){     
      for (int i=j;i<n;i+=2*nn){
        a[i+nn]*=tk;
        a[i]+=a[i+nn];
        a[i+nn]=a[i]-a[i+nn]*2;
      }
      tk*=w;
    }
    nn*=2;
  }
}
void fft_smesh(int n,pnt* a,int dr){
  if (n==1) return;
  if (n<=1<<9){
    fft_forv(n,a,dr);
    return;
  }

  /*
  if  (n == 2) {
    a[0] += a[1];
    a[1] = a[0] - a[1] * 2;
    return;  
  }
  */

  n/=2;
  fft_smesh(n,a,dr);
  fft_smesh(n,a+n,dr);
  pnt w=pp[n];
  if (dr==-1)
    w=!w;
  pnt tk=pnt(1,0);
  for (int i=0;i<n;i++){
    a[i+n]=a[i+n]*tk;
    a[i]+=a[i+n];
    a[i+n]=a[i]-a[i+n]*2;      
    tk=tk*w;
  }
}
void calcbit(int n){
  int tk=1,ff;
  int lg=0; 
  while (tk<n){
    tk*=2;
    lg++;
  }
  p[0]=0;
  tk=0;
  for (int i=1;i<n;i++){
    ff=lg;
    do{
      ff--;
      tk^=1<<ff;
    } while (((tk>>ff)&1)==0);
    p[i]=tk;
  }
}
void revbit(int &n,pnt * a){
  for (int i=0;i<n;i++){
    if (p[i]>i)
      swap(a[i],a[p[i]]);
  }
}
void mul(int &an,pnt *a,int &cn,pnt *c){
  cn=an;
  fft_smesh(cn,a,1);
  a[cn]=a[0]; 
  for (int i=0;i<cn;i++){
    c[i]=c[i]+((a[i]+!a[cn-i])/2)*((a[i]-!a[cn-i])/2)*pnt(0,-1);
  }
}
 
void mul(int* a0, int* b0, int cn, int* c0) {
   for (int i=0;i<cn;i++) {
     a[p[i]].x = a0[i];
     a[p[i]].y = b0[i];
   }
   mul(cn,a,cn,c);
   revbit(cn,c);
   fft_smesh(cn,c,-1);
   for (int i=0;i<cn;i++)
     c[i]=c[i]/cn;
    for (int i=0;i<cn;i++){
       c0[i] = c[i].x > 0.5;
    }
}



string s0 = "ACGT";
int sum[maxn];
int poly1[maxn];
int poly2[maxn];
int res[maxn];
int bad[maxn];
char s1[maxn];
char s2[maxn];
int main(){
  #ifdef LOCAL
//  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(".in","rt",stdin));
  #endif
  int n, m, k;
  scanf("%d %d %d\n", &n, &m, &k);

  for (int i=0;(1 << i) < maxn;i++){
    pp[1<<i]=pnt(cos(PI/(1<<i)),sin(PI/(1<<i)));
  }
  int cn=1;
  while (cn<n + m){
    cn*=2;
  }
  calcbit(cn);

  scanf("%s\n%s\n", s1, s2);
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < n; i++) {
      sum[i] = 0;
    }
    for (int i = 0; i < n; i++) if (s1[i] == s0[j]) {
      sum[max(0, i - k)]++;
      sum[min(n, i + k + 1)]--;
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur += sum[i];
      if (cur == 0) {
        poly1[i] = 1;
      } else {
        poly1[i] = 0;
      }
    }
    for (int i = 0; i < m; i++) {
      if (s2[i] == s0[j]) {
        poly2[m - 1 - i] = 1;
      } else {
        poly2[m - 1 - i] = 0;
      }
    }
    mul(poly1, poly2, cn, res);
    for (int i = m - 1; i < n + m; i++) {
      if (res[i] > 0) {
        bad[i - (m - 1)] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n - m; i++) if (bad[i] == 0) {
    ans++;
  }
  cout << ans;// << endl;
//  cerr<<clock()*1./CLOCKS_PER_SEC<<endl;
  return 0;
}