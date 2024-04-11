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
inline int f(int x,int y){
	int z;
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&z);
	return z;
}
int v[MN];
int main(){
	int n;
	scanf("%d",&n);
	int a,b,c;
	a=f(1,2);
	b=f(1,3);
	c=f(2,3);
	v[2]=a+c-b;
	v[1]=a-v[2];
	v[3]=c-v[2];
	F(i,4,n){
		int d=f(i-1,i);
		v[i]=d-v[i-1];
	}
	printf("! ");
	F(i,1,n)printf("%d%c",v[i]," \n"[i==n]);
	fflush(stdout);
	return 0;
}