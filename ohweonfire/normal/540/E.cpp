#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=400005;
int n,opx[maxn],opy[maxn];
int arr[maxn],val[maxn];
vector<int> all;
LL ww[maxn];
void add(int x,int y)
{
	for(;x<=n;x+=x&-x)ww[x]+=y;
}
LL calc(int x)
{
	LL ret=0;
	for(;x>0;x-=x&-x)ret+=ww[x];
	return ret;
}
int find(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",opx+i,opy+i);
		all.push_back(opx[i]);
		all.push_back(opx[i]+1);
		all.push_back(opy[i]);
		all.push_back(opy[i]+1);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=1;i<=n;i++)
	{
		opx[i]=find(opx[i])+1;
		opy[i]=find(opy[i])+1;
	}
	LL ans=0;
	for(int i=1;i<all.size();++i)val[i]=all[i]-all[i-1];
	val[all.size()]=1;
	for(int i=1;i<=all.size();i++)arr[i]=i;
	for(int i=1;i<=n;i++)swap(arr[opx[i]],arr[opy[i]]);
	n=all.size();
	for(int i=1;i<=n;++i)
	{
		ans=ans+(calc(n)-calc(arr[i]))*1ll*val[i];
		add(arr[i],val[i]);
	}
	cout<<ans<<endl;
}
//5
//1 9999991
//2 9999992
//3 9999993
//4 9999994
//5 9999995