#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n;
int a[MN],b[MN],c[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)scanf("%d",b+i);
	F(i,1,n)scanf("%d",c+i);
	int lst=0;
	F(i,1,n){
		int nxt=0;
		if(i!=n){
			if(a[i]!=lst)nxt=a[i];
			if(b[i]!=lst)nxt=b[i];
			if(c[i]!=lst)nxt=c[i];
		}else{
			if(a[i]!=lst&&a[i]!=c[1])nxt=a[i];
			if(b[i]!=lst&&b[i]!=c[1])nxt=b[i];
			if(c[i]!=lst&&c[i]!=c[1])nxt=c[i];
		}
		printf("%d%c",nxt," \n"[i==n]);
		lst=nxt;
	}
}	return 0;
}