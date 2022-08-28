#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod1=998244353,mod2=1e9+9;
int b1=8732481,b2=9345825,ib1,ib2,a1[200005],ia1[200005],a2[200005],ia2[200005],pn=2e5;
inline int addmod1(int x)
{
	return x>=mod1?x-mod1:x;
}
inline int addmod2(int x)
{
	return x>=mod2?x-mod2:x;
}
inline int submod1(int x)
{
	return x<0?x+mod1:x;
}
inline int submod2(int x)
{
	return x<0?x+mod2:x;
}
int fpow(int x,int y,int mod)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
struct str
{
	int l,h1,h2;
	str(int l=0,int h1=0,int h2=0):l(l),h1(h1),h2(h2){}
};
str operator+(const str &x,const str &y)
{
	return str(x.l+y.l,addmod1(1ll*x.h1*a1[y.l]%mod1+y.h1),addmod2(1ll*x.h2*a2[y.l]%mod2+y.h2));
}
str operator-(const str &x,const str &y)
{
	return str(x.l-y.l,1ll*submod1(x.h1-y.h1)*ia1[y.l]%mod1,1ll*submod2(x.h2-y.h2)*ia2[y.l]%mod2);
}
bool operator==(const str &x,const str &y)
{
	return x.l==x.l&&x.h1==y.h1&&x.h2==y.h2;
}
bool operator!=(const str &x,const str &y)
{
	return x.l!=x.l||x.h1!=y.h1||x.h2!=y.h2;
}
int n,m,q,vis[1000005],a[100005],st[100005][3],tp,st2[100005];
str pre[1000005],suf[1000005];
str querypre(int x,int l,int r,int k)
{
//	printf("pre:x=%d,l=%d,r=%d,k=%d\n",x,l,r,k);
	if(!k) return str(0,0);
	if(pre[x].l==k) return pre[x];
	int mid=(l+r)/2;
	if(pre[x*2].l>=k) return querypre(x*2,l,mid,k);
	return (querypre(x*2+1,mid+1,r,k-pre[x*2].l+suf[x*2].l)-suf[x*2])+pre[x*2];
}
str querysuf(int x,int l,int r,int k)
{
	//printf("suf:x=%d,l=%d,r=%d,k=%d\n",x,l,r,k);
	if(!k) return str(0,0);
	if(suf[x].l==k) return suf[x];
	int mid=(l+r)/2;
	if(suf[x*2+1].l>=k) return querysuf(x*2+1,mid+1,r,k);
	return (querysuf(x*2,l,mid,k-suf[x*2+1].l+pre[x*2+1].l)-pre[x*2+1])+suf[x*2+1];
}
void pushup(int x,int l,int r)
{
	if(vis[x*2]||vis[x*2+1])
	{
		vis[x]=1;
		return;
	}
	int mid=(l+r)/2;
	vis[x]=0;
	if(suf[x*2].l<=pre[x*2+1].l)
	{
		str nw=querypre(x*2+1,mid+1,r,suf[x*2].l);
		if(nw!=suf[x*2])
		{
			vis[x]=1;
			return;
		}
		pre[x]=(pre[x*2+1]-suf[x*2])+pre[x*2];
		suf[x]=suf[x*2+1];
	}
	else
	{
		str nw=querysuf(x*2,l,mid,pre[x*2+1].l);
		if(nw!=pre[x*2+1])
		{
			vis[x]=1;
			return;
		}
		pre[x]=pre[x*2];
		suf[x]=(suf[x*2]-pre[x*2+1])+suf[x*2+1];
	//	printf("a=%d,b=%d,suf=%d\n",(suf[x*2]-pre[x*2+1]).h1,suf[x*2+1].h1,suf[x].h1);
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		vis[x]=0;
		if(a[l]>0)
		{
			pre[x]=str();
			suf[x]=str(1,a[l],a[l]);
		}
		else
		{
			suf[x]=str();
			pre[x]=str(1,-a[l],-a[l]);
		}
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x,l,r);
//	printf("x=%d,l=%d,r=%d,vis=%d,pre=%d,%d,%d,suf=%d,%d,%d\n",x,l,r,vis[x],pre[x].l,pre[x].h1,pre[x].h2
//														,suf[x].l,suf[x].h1,suf[x].h2);
}
void modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		if(v>0)
		{
			pre[x]=str();
			suf[x]=str(1,v,v);
		}
		else
		{
			suf[x]=str();
			pre[x]=str(1,-v,-v);
		}
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x,l,r);
} 
void query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		st[++tp][0]=x;
		st[tp][1]=l;
		st[tp][2]=r;
		return;
	}
	int mid=(l+r)/2;
	query(x*2,l,mid,ql,qr);
	query(x*2+1,mid+1,r,ql,qr);
}
int main()
{
	ib1=fpow(b1,mod1-2,mod1);
	ib2=fpow(b2,mod2-2,mod2);
	a1[0]=ia1[0]=a2[0]=ia2[0]=1;
	for(int i=1;i<=pn;i++)
	{
		a1[i]=1ll*a1[i-1]*b1%mod1;
		ia1[i]=1ll*ia1[i-1]*ib1%mod1;
		a2[i]=1ll*a2[i-1]*b2%mod2;
		ia2[i]=1ll*ia2[i-1]*ib2%mod2;
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			modify(1,1,n,x,y);
		}
		else
		{
			tp=0;
			query(1,1,n,x,y);
			int fl=1,len=0;
			for(int i=1;i<=tp;i++)
			{
				int u=st[i][0];
				if(pre[u].l>len||vis[u])
				{
					fl=0;
				//	printf("i=%d,tp=1",i);
					break;
				}
				str nw;
				int sum=pre[u].l;
				for(int j=i-1;j;j--)
				{
					if(!sum) break;
					int v=st[j][0];
					if(st2[j]<=sum&&st2[j])
					{
						sum-=st2[j];
						nw=(suf[v]-querysuf(st[j][0],st[j][1],st[j][2],suf[v].l-st2[j]))+nw;
						st2[j]=0;
					}
					else if(st2[j]>sum)
					{
						nw=(querysuf(st[j][0],st[j][1],st[j][2],suf[v].l-st2[j]+sum)-querysuf(st[j][0],st[j][1],st[j][2],suf[v].l-st2[j]))+nw;
						st2[j]-=sum;
						sum=0;
					}
				}
				if(nw!=pre[u])
				{
					fl=0;
				//	printf("i=%d,tp=2",i);
					break;
				}
				st2[i]=suf[u].l;
				len=len-pre[u].l+suf[u].l;
			}
			if(len) fl=0;
			if(fl) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}