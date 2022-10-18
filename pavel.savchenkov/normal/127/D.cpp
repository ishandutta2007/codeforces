#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
 char s[1000010]; char *f="Just a legend";
 gets(s); int n=strlen(s);
 int pi[n+1]; pi[0]=0;
 for (int i=1;i<n;i++)
 {
  int j=pi[i-1];
  while (j>0&&s[i]!=s[j]) j=pi[j-1];
  if (s[i]==s[j]) j++;
  pi[i]=j;
 }
 int res=-1;
 if (pi[n-1]==0) {puts(f);return 0;}
 for (int i=1;i<n-1;i++)
  if (pi[i]==pi[n-1]) res=pi[i];

 if (res!=-1)
 {
  for (int i=0;i<res;i++)
   putchar(s[i]);
  return 0;
 }
 if (pi[pi[n-1]-1]==0) {puts(f);return 0;}
 for (int i=0;i<pi[pi[n-1]-1];i++)
  putchar(s[i]);
 return 0;
 }