#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
vector<long long>ans;
int n;
long long cal(int x)
{
	int y=n/x;
	return 1ll*x*y*(y-1)/2+y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i*i<=n;i++)
	if(n%i==0)
	{
		ans.push_back(cal(i));
		if(n/i!=i)ans.push_back(cal(n/i));
	}
	sort(ans.begin(),ans.end());
	int len=ans.size();
	rep(i,len)printf("%lld%c",ans[i-1]," \n"[i==len]);
	return 0;
}