#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j;
long long d,k,s[60];
char r[60];
int main() {
  scanf("%d%I64d",&n,&k); k++; n--; s[0]=1;
  for (i=1; i<=57; i++) s[i]=s[i-1]*2;
  for (i=0; i<=n; i++) {
    r[i]='0'; d=0;
    for (j=0; j<n; j++) if (j<n-j) {
      if (j>0 && r[n-j]!='0' && r[j]!='1') d+=s[max(0,j-i-1)]*s[min(max(0,n-j-i-1),n-2*j-1)];
      if (r[j]!=r[n-j] && r[n-j]!=0) break;
    }
	if (j==n) d+=s[max(0,n/2-i)];
    for (j=0; j<n; j++) if (j<=n-j) {
      if (j>0 && r[n-j]!='1' && r[j]!='1') d+=s[max(0,j-i-1)]*s[min(max(0,n-j-i-1),max(0,n-2*j-1))];
      if (r[j]==r[n-j] && r[j]!=0) break;
    }
	if (j==n && n%2==1) d+=s[max(0,n/2-i)];
    if (d<k) {
      if (i==0) { puts("-1"); return 0; }
      r[i]='1'; k-=d;
    }
  }
  puts(r);
  return 0;
}