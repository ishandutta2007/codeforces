#include <cstdio>
#include <cstring>
using namespace std;
char c[] = "hello";

int main() {
 char s[1000];
 gets(s);
 int n = (int)strlen(s); int j = 0;
 for (int i=0;i<n;i++)
   if (j<strlen(c)) if (s[i] == c[j]) j++;
 if (j==strlen(c)) puts("YES"); else puts("NO");
 return 0;
 }