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
int n,a[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	int s=0;
	F(i,1,n)scanf("%d",a+i),s^=a[i];
	if(!s){puts("DRAW");continue;}
	int t=31-__builtin_clz(s);
//	printf("t=%d\n",t);
	int o=0,z=0;
	F(i,1,n)if(a[i]>>t&1)++o;else++z;
//	printf("o=%d\n",one);
	if(o%4==3&&z%2==0)puts("LOSE");
	else if(o%4==1&&z%2==0)puts("WIN");
	else if(o%4==3)puts("WIN");
	else puts("WIN");
}	return 0;
}