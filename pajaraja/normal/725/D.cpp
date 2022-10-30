#include <bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> > q;
struct team
{
	long long w,t;
	int i;
};
team a[300001];
bool cmp(team a,team b) 
{
	if(a.t!=b.t) return a.t<b.t;
	return a.i>b.i;
}
int main(int argc, char** argv) 
{
	int n;
	long long t;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		a[i].i=i;
		scanf("%I64d%I64d",&a[i].t,&a[i].w);
	}
	sort(a,a+n,cmp);
	int g=n-1,d,miin;
	while(a[g].i!=0)
	{
		q.push(a[g].w-a[g].t+1);
		g--;
	}
	d=g;
	t=a[g].t;
	g--;
	miin=q.size();
	while(!q.empty()&&t>=0)
	{
		long long h=q.top();
		q.pop();
		t-=h;
		if(t<0) break;
		while(g>=0&&t<a[g].t) 
		{
			q.push(a[g].w-a[g].t+1);
			g--;
		}
		miin=miin>q.size()?q.size():miin;
	}
	printf("%d",miin+1);
	return 0;
}