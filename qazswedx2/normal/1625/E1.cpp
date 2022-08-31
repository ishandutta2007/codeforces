#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
inline int lowbit(int x)
{
	return x&-x;
}
struct BIT
{
	vector<ll> sum;
	int sz;
	void build(int x)
	{
		sz=x;
		sum.resize(x+1);
	}
	void modify(int x,ll v)
	{
		for(int i=x;i<=sz;i+=lowbit(i))
			sum[i]=sum[i]+v;
	}
	ll query(int x)
	{
		ll ans=0;
		for(int i=x;i;i-=lowbit(i))
			ans+=sum[i];
		return ans;
	}
}T,a[1000005];
int n,q,ct=1,f[1000005],sz[1000005],son[1000005],b[1000005],c[1000005];
char s[1000005];
int main()
{
	scanf("%d%d%s",&n,&q,s+1);
	int p=1;
	for(int i=1;i<=n;i++)
	{
	//	printf("i=%d,p=%d\n",i,p);
		if(s[i]=='(')
		{
			son[p]++;
			ct++;
			b[ct]=son[p];
			f[ct]=p;
			c[i]=ct;
			p=ct;
		}
		else
		{
			if(p==1) continue;
			c[i]=p;
			p=f[p];
		}
	}
	T.build(ct+1);
	for(int i=1;i<=ct;i++)
	{
		sz[i]=1;
		a[i].build(son[i]+1);
		T.modify(i,1ll*son[i]*(son[i]+1)/2);
	}
	for(int i=ct;i>1;i--)
		sz[f[i]]+=sz[i];
	for(int i=1;i<=q;i++)
	{
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			int x=c[l],y=f[x];
			a[y].modify(b[x],1);
			T.modify(y,-son[y]);
			son[y]--;
		}
		else
		{
			int x=c[l],y=c[r];
			ll ans=T.query(y+sz[y]-1)-T.query(x-1);
		//	printf("x=%d,y=%d,f=%d,%d,b=%d,%d\n",x,y,f[x],f[y],b[x],b[y]); 
			ll nw=a[f[x]].query(b[y])-a[f[x]].query(b[x]-1);
			nw=b[y]-b[x]+1-nw;
			ans+=1ll*nw*(nw+1)/2;
			printf("%lld\n",ans);
		}
	}
	return 0;
}