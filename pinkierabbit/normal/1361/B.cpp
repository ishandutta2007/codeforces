#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1100005
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,x;
int a[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&x);
	F(i,1,n)scanf("%d",a+i);
	if(x==1){printf("%d\n",n&1);continue;}
	sort(a+1,a+n+1);
	int kv=1000001,num=0,isinf=0;
	dF(i,n,1){
		int dif=kv-a[i];
		if(!isinf&&!num)kv=a[i],num=0;
		else if(dif>=22)kv=a[i],isinf=1,num=(ll)num*qpow(x,dif)%mod;
		else{
			while(kv>a[i]){
				if(isinf)
					num=(ll)num*x%mod;
				else{
					if(num<=inf/x)num*=x;
					else isinf=1,num=(ll)num*x%mod;
				}
				--kv;
			}
		}
//		debug("(%d,%d,%d)\n",kv,num,isinf);
		//================
		if(isinf){
			--num;
			if(num<0)num+=mod;
		}else{
			if(!num)num=1;
			else --num;
		}
	}
	int dif=kv;
	if(!isinf&&!num)kv=0,num=0;
	else if(dif>=22)kv=0,isinf=1,num=(ll)num*qpow(x,dif)%mod;
	else{
		while(kv){
			if(isinf)
				num=(ll)num*x%mod;
			else{
				if(num<=inf/x)num*=x;
				else isinf=1,num=(ll)num*x%mod;
			}
			--kv;
		}
	}
	printf("%d\n",num);
}	return 0;
}