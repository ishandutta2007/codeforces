#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
char buf[1<<20],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p1=buf,p2=buf+fread(buf,1,1<<20,stdin)),*p1++)
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
struct point
{
	ll x,y,z;
	point(){}
	point(ll x,ll y,ll z):x(x),y(y),z(z) {}
	bool operator< (const point& you)const
	{
		if(x==you.x)return y==you.y?z<you.z:y<you.y;
		return x<you.x;
	}
}a[MAXN];
int dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};
inline ll dist(point a,point b){return abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z);}
int n;
ll evaluate(point now)
{
	ll res=0;
	for(int i=1;i<=n;++i)umax(res,dist(now,a[i]));
	return res;
}
int main()
{
	int task=read();
	while(task--)
	{
		n=read();
		double sumx=0,sumy=0,sumz=0;
		for(int i=1;i<=n;++i)
		{
			a[i].x=read(),a[i].y=read(),a[i].z=read();
			sumx+=a[i].x,sumy+=a[i].y,sumz+=a[i].z;
		}
		point now(sumx/n,sumy/n,sumz/n);
		ll step=1ll<<60,ans=evaluate(now);
		//printf("now(%lld,%lld,%lld) %lld\n",now.x,now.y,now.z,ans);
		while(step)
		{
			while(1)
			{
				bool flag=0;
				point best=now;
				for(int tx=-1;tx<=1;++tx)
					for(int ty=-1;ty<=1;++ty)
						for(int tz=-1;tz<=1;++tz)
						{
							point nxt(now.x+tx*step,now.y+ty*step,now.z+tz*step);
							if(umin(ans,evaluate(nxt)))best=nxt,flag=1;
						}
				if(!flag)break;
				//printf("step=%lld,(%lld,%lld,%lld) -> (%lld,%lld,%lld)\n",step,now.x,now.y,now.z,best.x,best.y,best.z);
				now=best;
			}
			step>>=1;
		}
		printf("%lld %lld %lld\n",now.x,now.y,now.z);
	}
	return 0;
}