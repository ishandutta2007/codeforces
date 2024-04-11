#include <cstdio>
#include <cstring>

using namespace std;

int main() {
 char s[200];
 gets(s);
 if (strlen(s)==1) {if (s[0]>='a') s[0]+='Z'-'z'; else s[0]+='a'-'A' ;puts(s);return 0;}
 bool ok=true;
 int n=strlen(s);
 for (int i=1;i<n;i++) if (s[i]>='a') {ok=false;break;}
 if (ok) 
 { for (int i=0;i<n;i++)
   {if (s[i]>='a') s[i]+='Z'-'z';else s[i]+=-'A'+'a';putchar(s[i]);}
 }
 else puts(s);
 return 0;
 }