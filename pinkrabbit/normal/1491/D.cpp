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
int Solve(int u,int v,int k){
	if(u==v)return 1;
	if((u&1)==(v&1))return Solve(u>>1,v>>1,k);
	if(u&1)return Solve(u>>1,v>>1,k+1);
	if(k)return Solve(u>>1,v>>1,k-1);
	return 0;
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	int u,v;
	scanf("%d%d",&u,&v);
	if(u==v){puts("YES");continue;}
	if(v<u){puts("NO");continue;}
	if(__builtin_popcount(u)<__builtin_popcount(v)){puts("NO");continue;}
	if((u&-u)>(v&-v)){puts("NO");continue;}
	puts(Solve(u,v,0)?"YES":"NO");
}	return 0;
}