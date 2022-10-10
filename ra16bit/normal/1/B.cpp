#include <cstdio>
#include <cstring>
using namespace std;
int i,j,jj,k,n,m,a,b;
char s[30];
int main() {
  scanf("%d",&n); gets(s);
  for (i=0; i<n; i++) {
    gets(s); m=strlen(s);
    for (k=0, j=1; j<m; j++) if (s[j]>='0' && s[j]<='9' && (s[j-1]<'0' || s[j-1]>'9')) k++;
    if (k==2) {
      for (a=0, j=1; j<m && s[j]>='0' && s[j]<='9'; j++) a=a*10+s[j]-'0';
      for (b=0, j++; j<m && s[j]>='0' && s[j]<='9'; j++) b=b*10+s[j]-'0';
      for (j=0, k=26; b-k>0; k*=26, j++) b-=k;
      for (b--, k/=26; k>0; k/=26) { putchar('A'+b/k); b%=k; }
      printf("%d\n",a);
    } else {
      for (a=j=0; j<m && s[j]>='A' && s[j]<='Z'; j++) a=a*26+s[j]-'A';
      for (jj=j, k=26; j>1; j--, k*=26) a+=k;
      for (b=0, j=jj; j<m && s[j]>='0' && s[j]<='9'; j++) b=b*10+s[j]-'0';
      printf("R%dC%d\n",b,a+1);
    }
  }
  return 0;
}