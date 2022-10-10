#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MX=120;
int n,i,j,x[200200],y[200200];
long long b[200200];
double p,q,pp[MX],tot_b,tot_s,cb,cs;
ll cross(ll xa, ll ya, ll xb, ll yb) { return xa*yb-ya*xb; }
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
ll brd(ll a, ll b) { return gcd(abs(a),abs(b)); }
int main() {
  scanf("%d",&n);
  if (n>MX) {
    pp[1]=0.25;
    for (j=2; j<MX; j++) pp[j]=pp[j-1]*0.5;
  } else {
    for (p=q=i=1; i<=n; i++) q*=2;
    q-=n*(n+1.)*0.5+1;
    for (i=n-1; i>0; i--, p*=2) pp[i]=(p-1.)/q;
  }
  for (i=1; i<=n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    x[n+i]=x[i];
    y[n+i]=y[i];
  }
  for (i=2; i<=2*n; i++) b[i]=brd(x[i]-x[i-1],y[i]-y[i-1]);
  tot_b=b[2]+b[n+1];
  for (i=3; i<=n; i++) {
    tot_b+=b[i];
    tot_s+=abs(cross(x[i]-x[1],y[i]-y[1],x[i-1]-x[1],y[i-1]-y[1]));
  }
  for (i=1; i<=n; i++) {
    cb=cs=0;
    for (j=1; j<n-1 && j<MX; j++) {
      cb+=b[i+j];
      if (j>1) cs+=abs(cross(x[i+j]-x[i],y[i+j]-y[i],x[i+j-1]-x[i],y[i+j-1]-y[i]));
      tot_b+=pp[j]*(brd(x[i+j]-x[i],y[i+j]-y[i])-cb);
      tot_s-=pp[j]*cs;
    }
  }
  printf("%.14lf\n",double((tot_s-tot_b+2)*0.5));
  return 0;
}