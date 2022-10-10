#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,i,j,k;
char s[1010],t[1000100];
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); m=strlen(t);
  for (i=j=0; i<m; i++) if (t[i]==s[j]) if (++j==n) break;
  for (k=m-1, j=n-1; k>=0; k--) if (t[k]==s[j]) if (--j<0) break;
  printf("%d\n",max(0,k-i));
  return 0;
}