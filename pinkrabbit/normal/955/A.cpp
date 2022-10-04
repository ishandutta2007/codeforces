#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

int hh,mm;
int minl;
int H,D,C,N;
ld ans;

int main(){
	scanf("%d%d",&hh,&mm);
	scanf("%d%d%d%d",&H,&D,&C,&N);
	if(hh>=20) minl=0;
	else minl=(19-hh)*60+60-mm;
	ans=((H-1)/N+1)*C;
	ans=min(ans,((H+minl*D-1)/N+1)*C*0.8);
	printf("%lf",ans);
	return 0;
}