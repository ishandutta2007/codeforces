#include <bits/stdc++.h>
using namespace std;
int n,m,i,x,cur;
char s[11];
int main() {
  scanf("%d",&n);
  for (cur=i=0; i<n; i++) {
    scanf("%d",&x);
	scanf("%s",s);
	if (s[0]=='N') {
	  cur-=x;
	  if (cur<0) break;
	} else if (s[0]=='S') {
	  cur+=x;
	  if (cur>20000) break;
	} else if (cur==0 || cur==20000) break;
  }
  puts((i<n || cur!=0)?"NO":"YES");
  return 0;
}