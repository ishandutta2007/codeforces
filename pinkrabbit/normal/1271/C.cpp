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
int n,a,b;
int x[MN],y[MN],e,f,g,h;
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){e=f=g=h=0;
	scanf("%d%d%d",&n,&a,&b);
	F(i,1,n)scanf("%d%d",x+i,y+i);
	F(i,1,n){
		if(x[i]<a)++e;
		if(x[i]>a)++f;
		if(y[i]<b)++g;
		if(y[i]>b)++h;
	}
	int z=max({e,f,g,h});
	printf("%d\n",z);
	if(e==z)printf("%d %d\n",a-1,b);
	else if(f==z)printf("%d %d\n",a+1,b);
	else if(g==z)printf("%d %d\n",a,b-1);
	else printf("%d %d\n",a,b+1);
}	return 0;
}