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
#define N 3010
using namespace std;
ll n,k;
char buf[N];
vector<ll> ts;
vector<vector<ll> > ans;
string s,model;
int main(){
	ll i,j,sum=0;
	scanf("%I64d%I64d%s",&n,&k,&buf);
	s=buf;
	model=s;
	sort(model.begin(),model.end());
	for(i=0;i<k;i++)
	{
		if(s==model)
		{
			break;
		}
		ts.clear();
		for(j=0;j+1<s.size();j++)
		{
			if(s[j]=='R'&&s[j+1]=='L')
			{
				ts.push_back(j+1);
			}
		}
		for(j=0;j<ts.size();j++)
		{
			swap(s[ts[j]-1],s[ts[j]]);
		}
		if(ts.size())
		{
			ans.push_back(ts);
			sum+=ts.size();
		}
	}
	if(s!=model||sum<k)
	{
		puts("-1");
		return 0;
	}
	j=0;
	i=0;
	sum=0;
	while(i<ans.size())
	{
		if(sum+ans.size()-i==k)
		{
			break;
		}
		sum++;
		printf("1 ");
		if(j==ans[i].size())
		{
			j=0;
			i++;
		}
		printf("%I64d\n",ans[i][j]);
		j++;
		if(j==ans[i].size())
		{
			i++;
			j=0;
		}
	}
	printf("%I64d ",ans[i].size()-j);
	for(;j<ans[i].size();j++)
	{
		printf("%I64d ",ans[i][j]);
	}
	puts("");
	i++;
	for(;i<ans.size();i++)
	{
		printf("%I64d ",ans[i].size());
		for(j=0;j<ans[i].size();j++)
		{
			printf("%I64d ",ans[i][j]);
		}
		puts("");
	}
	return 0;
}