#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
};
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<point> a(5);
		for(int i=1;i<=3;i++)
			cin>>a[i].x>>a[i].y;
		point b;
		cin>>b.x>>b.y;
		int corner=0;
		for(int i=1;i<=3;i++)
		{
			if(a[i].x==1 and a[i].y==1)corner=i;
			if(a[i].x==1 and a[i].y==n)corner=i;
			if(a[i].x==n and a[i].y==1)corner=i;
			if(a[i].x==n and a[i].y==n)corner=i;
		}
		for(int i=1;i<=3;i++)
		{
			if(a[i].x==2 and a[i].y==2)corner=0;
			if(a[i].x==2 and a[i].y==n-1)corner=0;
			if(a[i].x==n-1 and a[i].y==2)corner=0;
			if(a[i].x==n-1 and a[i].y==n-1)corner=0;
		}
		if(corner)
		{
			if(b.x!=a[corner].x and b.y!=a[corner].y)
			{
				cout<<"NO"<<endl;
			}
			else
			{
				cout<<"YES"<<endl;
			}
		}
		else
		{
			int xs=2-a[1].x%2-a[2].x%2-a[3].x%2;
			int ys=2-a[1].y%2-a[2].y%2-a[3].y%2;
			if(b.x%2==xs and b.y%2==ys)
			{
				cout<<"NO"<<endl;
			}
			else
			{
				cout<<"YES"<<endl;
			}
		}
	}
	return 0;
}