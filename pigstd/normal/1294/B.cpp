#include<bits/stdc++.h>
using namespace std;

const int M=1005;
struct node
{
	int x,y;
}a[M];
int T;

bool cmp(node a,node b)
{
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a+1,a+1+n,cmp);
		bool flag=1;
		string ans="";
		for (int i=1;i<=n;i++)
		{
			if (a[i].y<a[i-1].y)
				{flag=0;break;}
			for (int j=1;j<=(a[i].x-a[i-1].x);j++)
				ans=ans+"R";
			for (int j=1;j<=(a[i].y-a[i-1].y);j++)
				ans=ans+"U";
		}
		if (!flag)
			printf("NO\n");
		else
		{
			printf("YES\n");
			cout<<ans<<endl;
		}
	}
	return 0;
}