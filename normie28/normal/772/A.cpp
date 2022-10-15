#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN=1e5+4;
const ld MAXV=1e18;
ll a[MAXN],b[MAXN];
ld exhaust[MAXN];
int n;
ll P;
bool f(ld imid) {
	ld needsum=0;
	for (int i=0;i<n;i++) {
		ld need=max(0.0L, (imid-exhaust[i])*a[i]);
		needsum+=need;
	}
	ld supply=imid*P;
	return supply>=needsum;
}
int main() 
{
	cin>>n>>P;
	for (int i=0;i<n;i++) {
	    cin>>a[i]>>b[i];
	}
	ll suma=0;
	for (int i=0;i<n;i++) {
		suma+=a[i];
	}
	if (P>=suma) {
		cout<<-1<<endl;
		return 0;
	}
	for (int i=0;i<n;i++) {
		exhaust[i]=((ld)b[i])/((ld)a[i]);
	}
	ld imin=0,imax=MAXV;
	for (ll iter=0;iter<220;iter++) {
		ld imid=(imin+imax)/2;
		if (f(imid)) imin=imid;
		else imax=imid;
	}
	if (imax>MAXV-100) cout<<-1<<endl;
	else printf("%.9f\n",(double)imin);
}