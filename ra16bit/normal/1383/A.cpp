#include <bits/stdc++.h>
using namespace std;
int r,t,i,j,k,n;
bool c[22][22];
char a[100100],b[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
	for (i=0; i<20; i++) for (j=0; j<20; j++) c[i][j]=false;
	scanf("%s",a);
	scanf("%s",b);
	for (i=0; i<n; i++) if (a[i]!=b[i]) c[a[i]-'a'][b[i]-'a']=true;
	bool ok=true;
	for (i=0; i<20; i++) for (j=0; j<i; j++) if (c[i][j]) ok=false;
	if (!ok) { puts("-1"); continue; }
	for (r=i=0; i<20; i++) {
	  for (j=i+1; j<20; j++) if (c[i][j]) break;
	  if (j<20) {
	    r++;
		for (k=j+1; k<20; k++) if (c[i][k]) c[j][k]=true;
	  }
	}
	printf("%d\n",r);
  }
  return 0;
}