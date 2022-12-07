#include<bits/stdc++.h>
using namespace std;
struct Tree
{
	int l,r,c;
}tree[800010];
const int mod=998244353;
int ksm(int i,int j)
{
	long long k=1,l=i;
	while(j)
	{
		if(j&1)
			k=k*l%mod;
		l=l*l%mod;
		j=j>>1;
	}
	return k;
}
int inv(int i)
{
	return ksm(i,mod-2);
}
int divi(int i,int j)
{
	return i*1ll*inv(j)%mod;
}
int num[200020];
Tree merge(Tree a,Tree b)
{
	Tree c;
	c.l=(a.l+a.r*1ll*b.l)%mod;
	c.r=a.r*1ll*b.r%mod;
	c.c=(a.c+a.r*1ll*b.c)%mod;
	return c;
}
void bt(int i,int l,int r)
{
	if(l==r)
	{
		tree[i].l=(mod+1-divi(num[l],100))%mod;
		tree[i].r=divi(num[l],100);
		tree[i].c=1;
		return;
	}
	int mid=(l+r)>>1;
	bt(i*2,l,mid);
	bt(i*2+1,mid+1,r);
	tree[i]=merge(tree[i*2],tree[i*2+1]);
}
Tree get(int i,int l,int r,int x,int y)
{
	if(l==x&&r==y)
		return tree[i];
	int mid=(l+r)>>1;
	if(x>mid)
		return get(i*2+1,mid+1,r,x,y);
	else
		if(y<=mid)
			return get(i*2,l,mid,x,y);
		else
			return merge(get(i*2,l,mid,x,mid),get(i*2+1,mid+1,r,mid+1,y));
}
int n,q;		
int getans(int l,int r)
{
	Tree tmp=get(1,1,n,l,r);
	return divi(tmp.c,(mod+1-tmp.l)%mod);
}
set<int> s;
int main()
{
	cin>>n>>q;
	s.insert(1);
	s.insert(n+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	bt(1,1,n);
	long long ans=getans(1,n);
	while(q--)
	{
		int t1;
		scanf("%d",&t1);
		if(s.count(t1))
		{			
			set<int>::iterator it;
			it=s.upper_bound(t1);
			int r=(*it)-1;
			it--;
			it--;
			int l=(*it);
			s.erase(t1);
			ans=(ans-getans(l,t1-1)+mod)%mod;
			ans=(ans-getans(t1,r)+mod)%mod;
			ans=(ans+getans(l,r))%mod;
			cout<<ans<<endl;
		}
		else
		{
			set<int>::iterator it;
			it=s.upper_bound(t1);
			int r=(*it)-1;
			it--;
			int l=(*it);
			s.insert(t1);
			ans=(ans+getans(l,t1-1))%mod;
			ans=(ans+getans(t1,r))%mod;
			ans=(ans+mod-getans(l,r))%mod;
			cout<<ans<<endl;
		}
	}			
}