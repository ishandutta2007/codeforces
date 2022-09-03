#include<cstdio>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> ans;
int a,b,c;
int dsum(ll x)
{
	int res=0;
	while(x)
	{
		res+=x%10;
		x/=10;
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=81;i++)
	{
		ll prod=1;
		for(int j=1;j<=a;j++)
			prod*=i;
		prod*=b;
		prod+=c;
		if(dsum(prod)==i&&prod<1000000000)
			ans.push_back(prod);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	return 0;
}