#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
char st[8];
string a,s,b[8],r[888];
int i,n,e;
bool u[8];
void rec(int l) {
  int i;
  if (l==6) {
    for (i=0; i<3; i++) b[i]=a.substr(2*i,2);
    sort(b,b+3);
	r[n++]=b[0]+b[1]+b[2];
    return;
  }
  for (i=0; i<6; i++) if ((!u[i]) && (((l&1)==0) || s[i]>=a[l-1])) {
    a[l]=s[i]; u[i]=true;
	rec(l+1); u[i]=false;
  }
}
int main() {
  scanf("%s",st); a=s=st;
  sort(s.begin(),s.end());
  rec(0);
  sort(r,r+n);
  if (r[i][0]!=r[i][1] && r[i][2]!=r[i][3] && r[i][4]!=r[i][5]) e=2; else e=1;
  for (i=1; i<n; i++) if (r[i]!=r[i-1]) {
    e++;
	if (r[i][0]!=r[i][1] && r[i][2]!=r[i][3] && r[i][4]!=r[i][5]
	    && r[i].substr(0,2)!=r[i].substr(2,2) && r[i].substr(2,2)!=r[i].substr(4,2) && r[i].substr(0,2)!=r[i].substr(4,2)) e++;
  }
  printf("%d\n",e);
  return 0;
}