#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int ra[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
const string rb[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int n,m,b,n1,i,r[77];
char s[1077],c;
long long a,x;
void getnum() {
  scanf("%s",s); n1=strlen(s);
  for (x=1, i=n1-1; i>=0; x*=n, i--) if (s[i]>='A') a+=(s[i]-'A'+10)*x; else a+=(s[i]-'0')*x;
}
int main() {
  scanf("%d",&n);
  c=getchar();
  while (c!='R' && (c<'0' || c>'9')) c=getchar();
  if (c=='R') {
    getnum();
    for (i=0; i<13; i++) while (a>=ra[i]) {
      printf("%s",rb[i].c_str());
      a-=ra[i];
    }
    return 0;
  } else while (c>='0' && c<='9') {
    b=b*10+c-'0';
    c=getchar();
  }
  getnum();
  if (a==0) { puts("0"); return 0; }
  for (m=0; a>0; m++, a/=b) r[m]=a%b;
  for (i=m-1; i>=0; i--) if (r[i]>9) putchar(r[i]-10+'A'); else putchar(r[i]+'0');
  return 0;
}