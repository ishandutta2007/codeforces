#include <cstdio>
#include <string>
using namespace std;
const string c[5]={"S","M","L","XL","XXL"};
int n[5],m,i,j,l,r,x;
char st[7];
string s;
int main() {
  for (i=0; i<5; i++) scanf("%d",&n[i]);
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%s",st); s=st;
    for (j=0; j<5; j++) if (c[j]==s) { x=j; break; }
    if (n[x]>0) {
      puts(c[x].c_str()); n[x]--;
      continue;
    }
    l=x-1; r=x+1;
    while (true) {
      if (r<5 && n[r]>0) {
        puts(c[r].c_str()); n[r]--;
        break;
      } else if (l>=0 && n[l]>0) {
        puts(c[l].c_str()); n[l]--;
        break;
      }
      l--; r++;
    }
  }
  return 0;
}