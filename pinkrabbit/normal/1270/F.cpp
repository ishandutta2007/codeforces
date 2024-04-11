#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 200005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define BB 500
int n,a[MN],t,o[MN];
char s[MN];
int sum[MN],buk[100000005];
ll ans;
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	F(i,1,n)if(s[i]=='1')a[i]=1,o[++t]=i;
	o[0]=0,o[t+1]=n+1;
	F(k,1,BB){
		buk[sum[0]=n]=1;
		F(i,1,n)sum[i]=sum[i-1]-1+(a[i]?k:0),ans+=buk[sum[i]]++;
		F(i,1,n)buk[sum[i]]=0;
	}
	if(n>BB){
		sum[0]=0;
		F(i,1,n)sum[i]=sum[i-1]+a[i];
		int b=n/(BB+1);
		F(i,1,n){
			int r=min(sum[i-1]+b,t);
			F(j,sum[i-1]+1,r){
				int c=j-sum[i-1],lb=o[j]-i,rb=o[j+1]-i;
				//k*c \in [lb,rb]
				if(BB*c<=lb)ans+=rb/c-lb/c;
				else if(BB*c<=rb)ans+=(rb-BB*c)/c;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}