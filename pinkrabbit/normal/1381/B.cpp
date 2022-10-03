#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 2005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,a[MN*2];
vector<int>c;
bitset<2005>b;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,2*n)scanf("%d",a+i);
	c.clear();
	int mx=0,len=0;
	F(i,1,2*n){
		if(a[i]>mx)len?c.pb(len):void(),mx=a[i],len=1;
		else++len;
	}c.pb(len);
	b.reset();b[0]=1;
	for(int x:c)b|=b<<x;
	puts(b[n]?"YES":"NO");
}	return 0;
}

/*
6
2
2 3 1 4
2
3 1 2 4
4
3 2 6 1 5 7 8 4
3
1 2 3 4 5 6
4
6 1 3 7 4 5 8 2
6
4 3 2 5 1 11 9 12 8 6 10 7

*/