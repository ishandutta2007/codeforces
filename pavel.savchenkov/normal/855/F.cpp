#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define mod 1000000007
#define bitcount __builtin_popcountll
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define pii pair<pi,int>
#define mp make_pair
ll ans[1000];
int upper[1000],lower[1000];
int block;
map <int,int> low[1000],up[1000];
map <int,int> vnotup[1000],vnotdown[1000];
int notboth[1000];
int minup[100005],mindown[100005];
void updateup(int i,int l,int r,int val)
{
	if(upper[i]<=val)
		return;
	//map<int,int> m;
	map<int,int> :: iterator it;
	//m.clear();
	for(int j=l;j<=r;j++)
	{
		if(minup[j]>val)
		{
			if(minup[j]==mod&&mindown[j]==mod&&upper[i]==mod&&lower[i]==mod)
			{
				notboth[i]--;
				//notdown[i]++;
				vnotdown[i][val]++;
				//notdownsum[i]+=val;
			}
			else if(minup[j]==mod&&upper[i]==mod)
			{
				//notup[i]--;
				int temp=min(lower[i],mindown[j]);
				vnotup[i][temp]--;
				if(vnotup[i][temp]==0)
					vnotup[i].erase(temp);
				//notupsum[i]-=min(lower[i],mindown[j]);
				up[i][val]++;
				low[i][temp]++;
				ans[i]+=val;
				ans[i]+=min(lower[i],mindown[j]);
			}
			else if(mindown[j]==mod&&lower[i]==mod)
			{
				int temp=min(upper[i],minup[j]);
				vnotdown[i][temp]--;
				if(vnotdown[i][temp]==0)
					vnotdown[i].erase(temp);
				vnotdown[i][val]++;
			}
			else
			{
				ans[i]+=val-min(upper[i],minup[j]);
				up[i][min(minup[j],upper[i])]--;
				up[i][val]++;
			}
			minup[j]=val;
		}
	}
}
void updatefullup(int i,int val)
{
	if(val>=upper[i])
		return;
	map <int,int> :: iterator it; 
	int n=up[i].size();
	n--;
	ll sum=0;
	int len2=0;
	for(it=vnotup[i].begin();it!=vnotup[i].end();it++)
	{
		ans[i]+=1ll*(it->fi)*(it->se)+1ll*(it->se)*val;
		len2+=it->se;
		low[i][it->fi]+=it->se;
	}
	vnotup[i].clear();
	it=vnotdown[i].upper_bound(val);
	int temp=0;
	for(it;it!=vnotdown[i].end();it++)
	{
		temp+=it->se;
	}
	it=vnotdown[i].upper_bound(val);
	vnotdown[i].erase(it,vnotdown[i].end());
	vnotdown[i][val]+=temp+notboth[i];
	notboth[i]=0;
	int len=0;
	it=up[i].upper_bound(val);
	for(it;it!=up[i].end();it++)
	{
		sum+=1ll*(it->fi)*(it->se);
		len+=it->se;
	}
	it=up[i].upper_bound(val);
	up[i].erase(it,up[i].end());
	ans[i]+=1ll*len*val-sum;
	up[i][val]+=len+len2;
	upper[i]=val;
}
void updatedown(int i,int l,int r,int val)
{
	if(lower[i]<=val)
		return;
	//map<int,int> m;
	map<int,int> :: iterator it;
	//m.clear();
	for(int j=l;j<=r;j++)
	{
		if(mindown[j]>val)
		{
			if(mindown[j]==mod&&minup[j]==mod&&upper[i]==mod&&lower[i]==mod)
			{
				notboth[i]--;
				//notup[i]++;
				//notupsum[i]+=val;
				vnotup[i][val]++;
			}
			else if(mindown[j]==mod&&lower[i]==mod)
			{
				//notdown[i]--;
				int temp=min(upper[i],minup[j]);
				vnotdown[i][temp]--;
				if(vnotdown[i][temp]==0)
					vnotdown[i].erase(temp);
				low[i][val]++;
				up[i][temp]++;
				//notdownsum[i]-=min(upper[i],minup[j]);
				ans[i]+=val;
				ans[i]+=min(upper[i],minup[j]);
			}
			else if(minup[j]==mod&&upper[i]==mod)
			{
				int temp=min(lower[i],mindown[j]);
				vnotup[i][temp]--;
				if(vnotup[i][temp]==0)
					vnotup[i].erase(temp);
				vnotup[i][val]++;
			}
			else
			{
				ans[i]+=val-min(lower[i],mindown[j]);
				low[i][min(mindown[j],lower[i])]--;
				low[i][val]++;
			}
			mindown[j]=val;
		}
	}
}
void updatefulldown(int i,int val)
{
	if(val>=lower[i])
		return;
	map <int,int> :: iterator it; 
	int n=low[i].size();
	n--;
	ll sum=0;
	int len2=0;
	for(it=vnotdown[i].begin();it!=vnotdown[i].end();it++)
	{
		ans[i]+=1ll*(it->fi)*(it->se)+1ll*(it->se)*val;
		len2+=it->se;
		up[i][it->fi]+=it->se;
	}
	vnotdown[i].clear();
	it=vnotup[i].upper_bound(val);
	int temp=0;
	for(it;it!=vnotup[i].end();it++)
	{
		temp+=it->se;
	}
	it=vnotup[i].upper_bound(val);
	vnotup[i].erase(it,vnotup[i].end());
	vnotup[i][val]+=temp+notboth[i];
	notboth[i]=0;
	int len=0;
	it=low[i].upper_bound(val);
	for(it;it!=low[i].end();it++)
	{
		sum+=1ll*(it->fi)*(it->se);
		len+=it->se;
	}
	it=low[i].upper_bound(val);
	low[i].erase(it,low[i].end());
	ans[i]+=1ll*len*val-sum;
	low[i][val]+=len+len2;
	lower[i]=val;
}
ll query(int i,int l,int r)
{
	ll sum=0;
	for(int j=l;j<=r;j++)
	{
		if(min(upper[i],minup[j])<mod&&min(lower[i],mindown[j])<mod)
			sum+=min(upper[i],minup[j])+min(lower[i],mindown[j]);
	}
	return sum;
}
ll queryfull(int i)
{
	return ans[i];
}
int main()
{
	int i,j,k,q,n,t,l,r,val,block;
	ll s;
	n=100000;
	for(i=0;i<1000;i++)
		lower[i]=upper[i]=mod;
	for(i=0;i<=100000;i++)
		minup[i]=mindown[i]=mod;
	block=300;
	for(i=1;i<=n;i++)
	{
		j=i/block;
		notboth[j]++;
	}
	sd(q);
	while(q--)
	{
		sd(t);
		sd(l);
		sd(r);
		r--;
		if(t==1)
		{
			sd(val);
			i=l/block;
			j=r/block;
			if(val>0)
			{
				if(i==j)
					updateup(j,l,r,val);
				else
				{
					updateup(i,l,(i+1)*block-1,val);
					i++;
					while(i<j)
					{
						// updateup(i,i*block,(i+1)*block-1,val);
						updatefullup(i,val);
						i++;
					}
					updateup(j,j*block,r,val);
				}
			}
			else
			{
				if(i==j)
					updatedown(j,l,r,-val);
				else
				{
					updatedown(i,l,(i+1)*block-1,-val);
					i++;
					while(i<j)
					{
						// updatedown(i,i*block,(i+1)*block-1,-val);
						updatefulldown(i,-val);
						i++;
					}
					updatedown(j,j*block,r,-val);
				}
			}
		}
		else
		{
			s=0;
			i=l/block;
			j=r/block;
			if(i==j)
				s=query(j,l,r);
			else
			{
				s=query(i,l,(i+1)*block-1);
				i++;
				while(i<j)
				{
					//s+=query(i,i*block,(i+1)*block-1);
					s+=queryfull(i);
					i++;
				}
				s+=query(j,j*block,r);
			}
			printf("%lld\n",s);
		}
	}
	return 0;
}