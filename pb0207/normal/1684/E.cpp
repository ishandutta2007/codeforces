#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n,a[N],k;

map<int,int>cnt;

vector<int>v;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		int tk=k;
		cnt.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		int MEX=-1;
		for(int i=0;i<=n*2;i++)
		{
			if(!k&&!cnt.count(i))
			{
				MEX=i;
				break;
			}
			if(!cnt.count(i))
				k--;
		}
		v.clear();
		for(auto [x,y]:cnt)
			if(x>MEX)
				v.push_back(y);
		sort(v.begin(),v.end());
		int ans=v.size();
		for(int i=0;i<v.size();i++)
		{
			int mn=min(v[i],tk);
			tk-=mn,v[i]-=mn;
			if(!v[i])
				ans--;
		}
		printf("%d\n",ans);
	}
}