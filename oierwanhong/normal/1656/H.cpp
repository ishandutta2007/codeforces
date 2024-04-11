#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef __int128 I128;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
I128 read_I128()
{
	I128 x=0;bool f=0;
	int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f?-x:x;
}
void write_I128(I128 x)
{
	if(!x){putchar('0'),putchar(' ');return;}
	int s[40],top=0;
	while(x)s[++top]=x%10,x/=10;
	while(top)putchar(s[top--]+'0');
	putchar(' ');
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 1011;
I128 gcd(I128 a,I128 b){return b?gcd(b,a%b):a;}
int L;
struct Segment_Tree
{
	I128 t[MAXN<<2|1];
#define rt t[num]
	void init(I128* arr,I128 x,un l=1,un r=L,un num=1)
	{
		if(l==r)
		{
			if(arr[l])rt=x/gcd(x,arr[l]);
			else rt=0;
			return;
		}
		un mid=(l+r)>>1;
		init(arr,x,l,mid,num<<1),init(arr,x,mid+1,r,num<<1|1);
		rt=gcd(t[num<<1],t[num<<1|1]);
	}
	void modify(un pos,I128 k,un l=1,un r=L,un num=1)
	{
		if(l==r){rt=k;return;}
		un mid=(l+r)>>1;
		if(pos<=mid)modify(pos,k,l,mid,num<<1);
		else modify(pos,k,mid+1,r,num<<1|1);
		rt=gcd(t[num<<1],t[num<<1|1]);
	}
	I128 Query(){return t[1];}
}Ta[MAXN],Tb[MAXN];
I128 a[MAXN],b[MAXN];
bool Da[MAXN],Db[MAXN];
pii Q[MAXN<<1|1];
int Qh,Qt;
int main()
{
	int task=read();
	while(task--)
	{
		memset(a,0,sizeof a),memset(b,0,sizeof b);
		int n=read(),m=read();
		L=max(n,m),Qh=Qt=0;
		for(int i=1;i<=n;++i)a[i]=read_I128(),Da[i]=0;
		for(int i=1;i<=m;++i)b[i]=read_I128(),Db[i]=0;
		for(int i=1;i<=n;++i)
		{
			Ta[i].init(b,a[i]);
			if(Ta[i].Query()>1)Q[Qt++]=pii(1,i),Da[i]=1;
		}
		for(int i=1;i<=m;++i)
		{
			Tb[i].init(a,b[i]);
			if(Tb[i].Query()>1)Q[Qt++]=pii(2,i),Db[i]=1;
		}
		while(Qh<Qt)
		{
			int type=Q[Qh].first,i=Q[Qh].second;++Qh;
			if(type==1)
			{
				for(int j=1;j<=m;++j)
					if(!Db[j])
					{
						Tb[j].modify(i,0);
						if(Tb[j].Query()!=1)Q[Qt++]=pii(2,j),Db[j]=1;
					}
			}
			else
			{
				for(int j=1;j<=n;++j)
					if(!Da[j])
					{
						Ta[j].modify(i,0);
						if(Ta[j].Query()!=1)Q[Qt++]=pii(1,j),Da[j]=1;
					}
			}
		}
		std::vector<int>ra,rb;
		for(int i=1;i<=n;++i)
			if(!Da[i])ra.emplace_back(i);
		for(int i=1;i<=m;++i)
			if(!Db[i])rb.emplace_back(i);
		if(ra.empty()||rb.empty())puts("NO");
		else
		{
			puts("YES");
			printf("%d %d\n",int(ra.size()),int(rb.size()));
			for(auto x:ra)write_I128(a[x]);
			puts("");
			for(auto x:rb)write_I128(b[x]);
			puts("");
		}
	}
	return 0;
}