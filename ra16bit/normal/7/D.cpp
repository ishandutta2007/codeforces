#include <cstdio>
#include <cstring>
using namespace std;
long long a,b,c,r,e=89,md=7420738134811LL;
int f[5000100],n,i;
char s[5000100];
int main() {
  gets(s+1); n=strlen(s+1);
  for (c=i=1; i<=n; i++, c=(c*e)%md) {
    a=a*e+s[i]-'0';  a%=md;
    b+=(s[i]-'0')*c; b%=md;
    if (a==b) f[i]=f[i/2]+1;
    r+=f[i];
  }
  printf("%I64d\n",r);
  return 0;
}