#include<bits/stdc++.h>
using namespace std;
int mx[1600010],ad[1600010];
void add(int i,int l,int r,int x,int y,int k)
{
	if(l==x&&r==y)
	{
		ad[i]+=k;
		mx[i]+=k;
		return;
	}
	int mid=(l+r)/2;
	if(x>mid)
		add(i*2+1,mid+1,r,x,y,k);
	else
		if(y<=mid)
			add(i*2,l,mid,x,y,k);
		else
		{
			add(i*2,l,mid,x,mid,k);
			add(i*2+1,mid+1,r,mid+1,y,k);
		}
	mx[i]=max(mx[i*2],mx[i*2+1])+ad[i];
}
pair<int,int> a[200010],b[200010];
pair<int,pair<int,int> > c[200010];
int mp[1000010];
int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&b[i].first,&b[i].second);	
	for(int i=1;i<=p;i++)
		scanf("%d%d%d",&c[i].first,&c[i].second.first,&c[i].second.second);	
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	sort(c+1,c+p+1);
	b[m+1].first=1000001;
	for(int i=1;i<=m;i++)
	{
		for(int j=b[i].first;j<b[i+1].first;j++)
			mp[j]=i;
		add(1,1,m,i,i,-b[i].second);
	}
	int np=0,ans=-2000000000;
	for(int i=1;i<=n;i++)
	{
		int nowans=-a[i].second;
		while(np<p)
		{
			if(c[np+1].first<a[i].first)
			{
				if(c[np+1].second.first<b[m].first)
				{
					add(1,1,m,mp[c[np+1].second.first]+1,m,c[np+1].second.second);
				}
				np++;
			}
			else
				break;
		}
		ans=max(nowans+mx[1],ans);
	}
	cout<<ans;
}