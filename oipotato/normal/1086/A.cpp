#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
struct data
{
	int x,y;
	friend bool operator <(const data&a,const data&b){return a.x<b.x;}
}a[10];
vector<pair<int,int>>ans;
int main()
{
	rep(i,3)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+4);
	if(a[1].y<=a[2].y)
	{
		for(int i=a[1].x;i<=a[2].x;i++)ans.push_back({i,a[1].y});
		for(int i=a[1].y+1;i<=a[2].y;i++)ans.push_back({a[2].x,i});
		if(a[3].y>a[2].y)
		{
			for(int i=a[2].x+1;i<=a[3].x;i++)ans.push_back({i,a[2].y});
			for(int i=a[2].y+1;i<=a[3].y;i++)ans.push_back({a[3].x,i});
		}
		else if(a[3].y<a[1].y)
		{
			for(int i=a[2].x+1;i<=a[3].x;i++)ans.push_back({i,a[1].y});
			for(int i=a[3].y;i<a[1].y;i++)ans.push_back({a[3].x,i});
		}
		else
		{
			for(int i=a[2].x+1;i<=a[3].x;i++)ans.push_back({i,a[3].y});
		}
	}
	else
	{
		for(int i=a[1].x;i<=a[2].x;i++)ans.push_back({i,a[1].y});
		for(int i=a[2].y;i<a[1].y;i++)ans.push_back({a[2].x,i});
		if(a[3].y>a[1].y)
		{
			for(int i=a[2].x+1;i<=a[3].x;i++)ans.push_back({i,a[1].y});
			for(int i=a[1].y+1;i<=a[3].y;i++)ans.push_back({a[3].x,i});
		}
		else if(a[3].y<a[2].y)
		{
			for(int i=a[2].x+1;i<=a[3].x;i++)ans.push_back({i,a[2].y});
			for(int i=a[3].y;i<a[2].y;i++)ans.push_back({a[3].x,i});
		}
		else
		{
			for(int i=a[2].x+1;i<=a[3].x;i++)ans.push_back({i,a[3].y});
		}
	}
	printf("%d\n",ans.size());
	for(auto i:ans)printf("%d %d\n",i.first,i.second);
	return 0;
}