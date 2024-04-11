#include <bits/stdc++.h>
using namespace std;
const int MX=400400;
int n,i,j,x,a,b,c;
vector<int> r;
bool u[MX];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
	if (x==1) a++;
  }
  b=n-a;
  u[0]=u[1]=true;
  for (i=2; i<MX; i++) if (!u[i]) for (j=i+i; j<MX; j+=i) u[j]=true;
  while (a>0 && b>0) {
    if (!u[c+1]) {
	  c++; a--;
	  r.push_back(1);
	} else {
	  c+=2; b--;
	  r.push_back(2);
	}
  }
  while (a>0) {
	r.push_back(1);
	a--;
  }
  while (b>0) {
	c+=2;
	b--;
	r.push_back(2);
  }
  for (i=0; i<n; i++) printf("%d ",r[i]);
  return 0;
}