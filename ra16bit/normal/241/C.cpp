#include <cstdio>
#include <algorithm>
using namespace std;
int hl,hr,n,i,res,it,l[111],r[111],v[111],u[111];
char s[7],t[111];
void solve(int HL, char ch, int HR) {
  int sum=0;
  double A=HL-HR,B=100000,C=-B*HL,eps=1e-8;
  ++it;
  for (int j=100, now=1; j<HR; j+=100, now^=1) {
    double x=(-B*j-C)/A;
    int k;
    for (k=0; k<n; k++) if (((now && t[k]==ch) || (now==0 && t[k]!=ch)) && x>l[k]-eps && x<r[k]+eps) {
      if (u[k]==it) return;
      u[k]=it;
      sum+=v[k];
      break;
    }
    if (k>=n) return;
  }
  res=max(res,sum);
}
int main() {
  scanf("%d%d%d",&hl,&hr,&n);
  for (i=0; i<n; i++) {
    scanf("%d",&v[i]);
    scanf("%s",s); t[i]=s[0];
    scanf("%d%d",&l[i],&r[i]);
  }
  for (i=1; i<111; i++) {
    solve(hl,'T',i*100+((i&1)?(100-hr):hr));
    solve(100-hl,'F',i*100+((i&1)?hr:(100-hr)));
  }
  printf("%d\n",res);
  return 0;
}