#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
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
int x[MN],y[MN];
bool chk(){
	F(i,1,n)if((x[i]&1)!=(x[1]&1)||(y[i]&1)!=(y[1]&1))return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d",x+i,y+i);
	while(chk())F(i,1,n)x[i]>>=1,y[i]>>=1;
//	F(i,1,n)printf("(%d,%d),",x[i],y[i]);
	int A=0;
	F(i,1,n)if((x[i]+y[i])&1)++A;
	if(A>0&&A<n){printf("%d\n",A);F(i,1,n)if((x[i]+y[i])&1)printf("%d ",i);return 0;}
	A=0;
	F(i,1,n)if(x[i]&1)++A;
	printf("%d\n",A);
	F(i,1,n)if(x[i]&1)printf("%d ",i);
	return 0;
}