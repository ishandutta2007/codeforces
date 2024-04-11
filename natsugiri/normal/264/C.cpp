#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;
const LL INF = 1LL<<60;

int n, q;
int v[100010], c[100010];
LL d[100010];

LL calc(LL a, LL b) {
    LL ret=0;
    int t0, t1;
    t0=n; t1=n+1;
    for (int i=0; i<n+2; i++) d[i]=-INF;
    for (int i=0; i<n; i++) {
	if (c[i]==t1) swap(t1, t0);
	
	if (c[i]==t0) {
	    d[t0]=max(d[t0],
		      max(d[t0]+a*v[i],
			  max(b*v[i], d[t1]+b*v[i])));
	} else {
	    if (d[t0]<d[t1]) swap(t1, t0);
	    d[c[i]]=max(d[c[i]],
			max(b*v[i],
			    max(d[t0]+b*v[i], d[c[i]]+a*v[i])));
	    if (d[t1]<d[c[i]]) t1=c[i];
	}
	ret=max(ret, d[c[i]]);
    }
	
    return ret;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i=0; i<n; i++) scanf("%d", v+i);
    for (int i=0; i<n; i++) scanf("%d", c+i);
    for (;q--;) {
	LL a, b; cin>>a>>b;
	cout<<calc(a, b)<<endl;
    }
    return 0;
}