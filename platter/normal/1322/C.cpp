#include <bits/stdc++.h>
using namespace std;

const long long ms[5]={ 1000000007,1000000007, 1000000009,1000000087,1000000097};
const int as[5]={302,359, 1039, 2797,3593};
long long arr[500000];
long long mod[2];
long long a[2];
long long gotl0[500000];
long long gotl1[500000];
typedef pair<long long,long long> P;

long long fastpow(long long x,long long y,int type) {
	if (y==0)
	return 1;
	if (y%2==1)
	return (fastpow(x,y-1,type)*x)%mod[type];
	long long half=fastpow(x,y/2,type);
	return (half*half)%mod[type];
}

long long gcd(long long x,long long y) {
	if (y==0)
	return x;
	return gcd(y,x%y);
}

int main(void) {
	mt19937 rd = mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> ran(0, 2147483647);
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
	    int one=ran(rd)%4;
	    mod[0]=ms[one];
    	a[one]=as[one];
    	int x=ran(rd)%4;
    	while (x==one) {
    		x=ran(rd)%4;
    	}
    	mod[1]=ms[x];
    	a[1]=as[x];
		int n,m;
		scanf("%d %d\n",&n,&m);
		for(int i=0;i<n;i++) {
			scanf("%lld ",&arr[i]);
		}
		scanf("\n");
		for(int i=0;i<m;i++) {
			int u,v;
			scanf("%d %d\n",&u,&v);
			u--;
			v--;
			gotl0[v]+=fastpow(a[0],u,0);
			gotl1[v]+=fastpow(a[1],u,1);
			gotl0[v]%=mod[0];
			gotl1[v]%=mod[1];
		}
		scanf("\n");
		map<P,long long> mp;
		for(int i=0;i<n;i++) {
		    if (gotl0[i]!=0||gotl1[i]!=0)
			mp[P(gotl0[i],gotl1[i])]+=arr[i];
		}
		long long ret=0;
		for(auto curr: mp) {
		    if (curr.second!=0)
			ret=gcd(curr.second,ret);
		}
		printf("%lld\n",ret);
		for(int i=0;i<n;i++) {
		    gotl0[i]=0;
		    gotl1[i]=0;
		}
	}
}