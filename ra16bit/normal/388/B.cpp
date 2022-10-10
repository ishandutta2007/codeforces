#include <cstdio>
#include <algorithm>
using namespace std;
int m,z,n,l,n1,l1,x,lastl,lastr,lastl_,lastr_,num,a[100100];
char s[1010][1010];
void solve(int x) {
  n=l=0;
  if (x<2) { l=x-1; return; }
  for (int i=2; i*i<=x; i++) while (x%i==0) { 
    n+=i; l++; x/=i;
  }
  if (x>1) { n+=x; l++; }
}
bool ok(int z) {
  solve(z);
  n1=n; l1=l;
  solve(m-z);
  int d=0;
  if (l1!=-1 && l!=-1) d=max(l,l1)-min(l,l1);
  return 2+n+n1+d<=1000;
}
void add(int x) {
//printf("[%d %d] -> [%d %d]\n",lastl,lastr,num+1,num+x);
  for (int i=lastl; i<=lastr; i++) for (int j=1; j<=x; j++) s[i][num+j]='Y';
  lastl=num+1;
  num+=x;
  lastr=num;
}
int main() {
  scanf("%d",&m);
  for (z=m; z>0; z--) if (ok(z)) {
    lastl=1;
    lastr=1;
    num=2;
    x=z;
    for (int i=2; i*i<=x; i++) while (x%i==0) { 
      add(i);
      x/=i;
    }
    if (x>1) add(x);
    lastl_=lastl;
    lastr_=lastr;
    if (z<m) {
      lastl=1;
      lastr=1;
      x=m-z;
      for (int i=2; i*i<=x; i++) while (x%i==0) { 
        add(i);
        x/=i;
      }
      if (x>1) add(x);
      if (l1<l) {
        for (int i=lastl; i<=lastr; i++) s[i][2]='Y';
        lastl=lastl_;
        lastr=lastr_;
        for (int i=l1; i<l; i++) add(1);
        for (int i=lastl; i<=lastr; i++) s[i][2]='Y';
      } else if (l<l1) {
        for (int i=l; i<l1; i++) add(1);
        for (int i=lastl; i<=lastr; i++) s[i][2]='Y';
        for (int i=lastl_; i<=lastr_; i++) s[i][2]='Y';
      } else {
        for (int i=lastl; i<=lastr; i++) s[i][2]='Y';
        for (int i=lastl_; i<=lastr_; i++) s[i][2]='Y';
      }
    } else {
      for (int i=lastl_; i<=lastr_; i++) s[i][2]='Y';
    }
    printf("%d\n",num);
    for (int i=1; i<=num; i++,puts("")) for (int j=1; j<=num; j++) 
      if (s[i][j]=='Y' || s[j][i]=='Y') putchar('Y'); else putchar('N');
    break;
  }
  return 0;
}