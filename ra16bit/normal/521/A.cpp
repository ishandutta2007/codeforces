#include <stdio.h>
const int md=1000000007;
int n,i,x,c,a[26];
char s[100100];
long long pw(int a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (a*pw(a,b-1))%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  for (i=0; i<n; i++) a[s[i]-'A']++;
  for (i=0; i<26; i++) if (a[i]>x) x=a[i];
  for (i=0; i<26; i++) if (a[i]==x) c++;
  printf("%d\n",int(pw(c,n)));
  return 0;
}