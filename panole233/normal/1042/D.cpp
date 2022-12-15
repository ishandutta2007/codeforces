#include<cstdio>
#include<cstring>

const long long L=-1000000000000000ll,R=1000000000000000ll;

int n,tot;
long long T,x,s,ans;

struct node
{
	int ls,rs,val;
}t[15000001];

int gnode() {t[++tot].ls=0; t[tot].rs=t[tot].val=0; return tot;}

int query(int i,long long l,long long r,long long ql,long long qr)
{
	if (ql==l&&qr==r) return t[i].val; 
	long long mid=(l+r)>>1;
	if (qr<=mid)
	{
		if (t[i].ls) return query(t[i].ls,l,mid,ql,qr);
		else return 0;
	} else
	if (ql>mid)
	{
		if (t[i].rs) return query(t[i].rs,mid+1,r,ql,qr);
		else return 0;
	} else
	{
		int ans=0;
		if (t[i].ls) ans+=query(t[i].ls,l,mid,ql,mid);
		if (t[i].rs) ans+=query(t[i].rs,mid+1,r,mid+1,qr);
		return ans;
	}
}

void add(int i,long long l,long long r,long long x)
{
	if (l==r) {t[i].val++; return;}
	long long mid=(l+r)>>1;
	if (x<=mid)
	{
		if (!t[i].ls) t[i].ls=gnode();
		add(t[i].ls,l,mid,x);
	} else
	{
		if (!t[i].rs) t[i].rs=gnode();
		add(t[i].rs,mid+1,r,x);
	}
	t[i].val=t[t[i].ls].val+t[t[i].rs].val;
}

int main()
{
	scanf("%d%I64d",&n,&T); T--; ans=0; t[0].val=0;
	t[1].ls=t[1].rs=t[1].val=0; tot=1;
	for (int i=1; i<=n; i++) 
	{
		scanf("%I64d",&x); if (x<=T) ans++;
		ans+=1ll*query(1,L,R,L,T-s-x);
		s+=x; add(1,L,R,x-s);
	}
	printf("%I64d\n",ans);
	return 0;
}