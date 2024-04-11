#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int n,i,m,e,q,a[100100];
char s[100100];
string cur;
int main() {
  gets(s); n=strlen(s); s[n]=' ';
  for (i=0; i<=n; i++) if (s[i]==' ') {
    m=cur.length();
    if (m>=4 && cur[m-1]=='s' && cur[m-2]=='o' && cur[m-3]=='i' && cur[m-4]=='l') a[e++]=0; else 
    if (m>=5 && cur[m-1]=='a' && cur[m-2]=='l' && cur[m-3]=='a' && cur[m-4]=='i' && cur[m-5]=='l') a[e++]=1; else 
    if (m>=3 && cur[m-1]=='r' && cur[m-2]=='t' && cur[m-3]=='e') a[e++]=2; else 
    if (m>=4 && cur[m-1]=='a' && cur[m-2]=='r' && cur[m-3]=='t' && cur[m-4]=='e') a[e++]=3; else 
    if (m>=6 && cur[m-1]=='s' && cur[m-2]=='i' && cur[m-3]=='t' && cur[m-4]=='i' && cur[m-5]=='n' && cur[m-6]=='i') a[e++]=4; else 
    if (m>=6 && cur[m-1]=='s' && cur[m-2]=='e' && cur[m-3]=='t' && cur[m-4]=='i' && cur[m-5]=='n' && cur[m-6]=='i') a[e++]=5; else {
      puts("NO");
      return 0;
    }
    cur="";
  } else cur+=s[i];
  for (i=0; i<e; i++) {
    if ((a[i]&1)!=(a[0]&1)) { puts("NO"); return 0; }
    if (a[i]>1 && a[i]<4) q++;
    if (i>0 && a[i]<a[i-1]) { puts("NO"); return 0; }
  }
  puts((e==1 || q==1)?"YES":"NO");
  return 0;
}