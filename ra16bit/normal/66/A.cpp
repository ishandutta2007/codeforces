#include <stdio.h>
#include <string.h>
char s[111];
unsigned long long a;
int i,n;
int main() {
  scanf("%s",s); n=strlen(s);
  if (s[0]=='-') {
    if (n<21) {
      for (i=1; i<n; i++) a=a*10+s[i]-'0';
      if (a<=128) { puts("byte"); return 0; }
      if (a<=32768) { puts("short"); return 0; }
      if (a<=2147483648LL) { puts("int"); return 0; }
      if (a<=9223372036854775808ULL) { puts("long"); return 0; }
    }
    puts("BigInteger");
  } else {
    if (n<20) {
      for (i=0; i<n; i++) a=a*10+s[i]-'0';
      if (a<128) { puts("byte"); return 0; }
      if (a<32768) { puts("short"); return 0; }
      if (a<2147483648LL) { puts("int"); return 0; }
      if (a<9223372036854775808ULL) { puts("long"); return 0; }
    }
    puts("BigInteger");
  }
  return 0;
}