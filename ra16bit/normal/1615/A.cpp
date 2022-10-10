#include <bits/stdc++.h>
using namespace std;
int t,n,a,s,i;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
	for (s=i=0; i<n; i++) { scanf("%d",&a); s+=a; }
	printf("%d\n",int(s%n!=0));
  }
  return 0;
}