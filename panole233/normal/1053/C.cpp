#include<cstdio>
#include<cstring>

const int mod=1000000007;
int n,a[200001],x,y,T[200001],q,l,r,mid,ans,Ans,w[200001],t1[200001],t2[200001];
long long t[200001];

int plus(int x,int y) {return (x+y>=mod)?(x+y-mod):(x+y);}

void add(int x,long long val)
{
	for (; x<=n; x+=(x&-x)) t[x]+=val;
}

long long query(int x)
{
	long long ans=0;
	for (; x; x-=(x&-x)) ans+=t[x];
	return ans;
}

void Add(int x,int val)
{
	for (; x<=n; x+=(x&-x)) T[x]=plus(T[x],val);
}

int Query(int x)
{
	int ans=0;
	for (; x; x-=(x&-x)) ans=plus(ans,T[x]);
	return ans;
}

long long calc(int l,int r) 
{
	if (l>r) return 0;
	return query(r)-query(l-1);
}

int Calc(int l,int r)
{
	if (l>r) return 0;
	return (Query(r)-Query(l-1)+mod)%mod;
}

void add1(int x,int val)
{
	for (; x<=n; x+=(x&-x)) t1[x]=plus(t1[x],val);
}

int query1(int x)
{
	int ans=0;
	for (; x; x-=(x&-x)) ans=plus(t1[x],ans);
	return ans;
}

void add2(int x,int val)
{
	for (; x<=n; x+=(x&-x)) t2[x]=plus(t2[x],val);
}

int query2(int x)
{
	int ans=0;
	for (; x; x-=(x&-x)) ans=plus(t2[x],ans);
	return ans;
}

int calc1(int l,int r)
{
	if (l>r) return 0;
	return (query1(r)-query1(l-1)+mod)%mod;
}

int calc2(int l,int r)
{
	if (l>r) return 0;
	return (query2(r)-query2(l-1)+mod)%mod;
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	memset(t,0,sizeof(t));
	memset(T,0,sizeof(T));
	memset(t1,0,sizeof(t1));
	memset(t2,0,sizeof(t2));
	for (int i=1; i<=n; i++) scanf("%d",&x),add(i,x),Add(i,1ll*x*a[i]%mod),w[i]=x,add1(i,1ll*i*x%mod),add2(i,1ll*(n-i+1)*x%mod);
	while (q--)
	{
		scanf("%d%d",&x,&y);
		if (x<0)
		{
			x=-x; add(x,y-w[x]); Add(x,1ll*(y-w[x]+mod)*a[x]%mod);
			add1(x,1ll*(y-w[x]+mod)*x%mod);
			add2(x,1ll*(y-w[x]+mod)*(n-x+1)%mod);
			w[x]=y;
		} else
		{
			l=x; r=y; ans=y+1;
			while (l<=r)
			{
				mid=(l+r)>>1;
				if (calc(x,mid-1)>=calc(mid,y)) ans=mid,r=mid-1; else l=mid+1;
			}
			ans--;
			Ans=(calc(x,ans-1)%mod*a[ans]-Calc(x,ans-1))%mod;
			Ans=(-calc(ans+1,y)%mod*a[ans]+Ans+Calc(ans+1,y))%mod;
			Ans=(Ans-calc2(x,ans-1)+calc(x,ans-1)%mod*(n-ans+1))%mod;
			Ans=(Ans-calc1(ans+1,y)+calc(ans+1,y)%mod*ans)%mod;
			printf("%d\n",(Ans+mod)%mod);
		}
	}
	return 0;
}