#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
#define MM 600005
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,ans;
ll a[MN];
int c[60];
int pw2[120];
int main(){int tests=1;scanf("%d",&tests);
	pw2[0]=1;
	F(i,1,119)pw2[i]=2*pw2[i-1]%mod;
while(tests--){
	scanf("%d",&n),ans=0;
	F(i,1,n)scanf("%lld",a+i);
	F(j,0,59)c[j]=0;
	F(i,1,n)
		F(j,0,59)
			if(a[i]>>j&1)++c[j];
	F(i,1,n){
		int s1=0,s2=0;
		F(j,0,59)
			if(a[i]>>j&1)s1=(s1+(ll)pw2[j]*c[j])%mod;
		F(j,0,59)
			if(a[i]>>j&1)s2=(s2+(ll)pw2[j]*n)%mod;
			else s2=(s2+(ll)pw2[j]*c[j])%mod;
		ans=(ans+(ll)s1*s2)%mod;
	}
	printf("\t\t%d\n",ans);
}	return 0;
}