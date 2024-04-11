#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

map<int,int> ma;
int x,n,k,s[200001];
long long ans;

long long calc(int x) {return 1ll*x*(x-1)/2;}

int main()
{
	scanf("%d%d",&n,&k);
	s[0]=0; ma.clear();
	for (int i=1; i<=n; i++) scanf("%d",&x),s[i]=s[i-1]^x;
	ans=0;
	for (int i=0; i<=n; i++)
		if (ma.find(s[i])==ma.end()) ma.insert(make_pair(s[i],1));
		else ma[s[i]]++;
	for (int i=0; i<=n; i++)
		if (ma[s[i]]) 
		{
			x=ma[s[i]];
			if (ma.find(s[i]^((1<<k)-1))!=ma.end()) x+=ma[s[i]^((1<<k)-1)];
			if (x&1) ans+=calc(x/2)+calc(x/2+1);
			else ans+=2ll*calc(x/2);
			ma[s[i]]=0; ma[s[i]^((1<<k)-1)]=0;
		}
	printf("%I64d\n",1ll*n*(n+1)/2-ans);
	return 0;
}