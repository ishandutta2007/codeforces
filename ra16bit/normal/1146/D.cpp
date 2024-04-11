#include <bits/stdc++.h>
using namespace std;
int n,a,b,x,y,z,e,ri,lst,fi,fr,q[100100],d[100100];
long long cnt,res;
bool u[100100];
int main() {
  scanf("%d%d%d",&n,&a,&b);
  u[0]=true; fr=1;
  while (fi<fr) {
    x=q[fi++];
	ri=d[x]-d[x]%a+x;
	if (ri>=d[x]) ri-=a;
	if (x<=ri) res+=((ri-x)/a+1LL)*(n-d[x]+1LL);
	ri+=a;
	lst=n-n%a+x;
	if (lst>n) lst-=a;
	if (ri<=lst) {
	  cnt=(lst-ri)/a+1;
	  res+=(n-lst+1LL)*cnt;
	  res+=((cnt*(cnt-1))/2)*a;
	}
	y=b-b%a+x;
	if (y<b) y+=a;
	e=max(y,d[x]);
	if (e<=n) for (y-=b; y>=0; y-=b) {
	  z=y%a;
	  if (!u[z]) {
	    u[z]=true;
	    d[z]=e;
	    q[fr++]=z;
	  } else break;
	}
  }
  cout<<res;
  return 0;
}