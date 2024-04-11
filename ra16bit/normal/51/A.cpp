#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int i,n,r;
string z,p,a[1111];
char s[7],t[7];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    if (i) scanf("%s",s);
    scanf("%s",s);
    scanf("%s",t);
    z=s[0]; z+=s[1]; z+=t[1]; z+=t[0];
    p=s[1]; p+=t[1]; p+=t[0]; p+=s[0];
    if (p<z) z=p;
    p=t[1]; p+=t[0]; p+=s[0]; p+=s[1]; 
    if (p<z) z=p;
    p=t[0]; p+=s[0]; p+=s[1]; p+=t[1]; 
    if (p<z) z=p;
    a[i]=z;
  }
  sort(a,a+n);
  for (i=r=1; i<n; i++) if (a[i]!=a[i-1]) r++;
  printf("%d\n",r);
  return 0;
}