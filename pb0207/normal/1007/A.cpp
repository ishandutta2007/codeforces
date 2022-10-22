#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N];

priority_queue<int,vector<int>,greater<int> >q;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		q.push(a[i]);
		if(q.top()<a[i])
		{
			q.pop();
			ans++;
		}
	}
	printf("%d",ans);
}