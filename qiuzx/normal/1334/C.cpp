#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
ll t,n,a[N],b[N],dam[N],ans;
int main(){
	ll i,sum;
	t=rint();
	while(t--)
	{
		n=rint();
		for(i=0;i<n;i++)
		{
			a[i]=rint();
			b[i]=rint();
		}
		dam[0]=max((ll)0,a[0]-b[n-1]);
		sum=dam[0];
		for(i=1;i<n;i++)
		{
			dam[i]=max((ll)0,a[i]-b[i-1]);
			sum+=dam[i];
		}
		ans=LINF;
		for(i=0;i<n;i++)
		{
			ans=min(ans,a[i]+sum-dam[i]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}