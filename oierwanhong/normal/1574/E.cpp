#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 2000011,mod = 998244353;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
struct Mint
{
	int x;
	Mint():x(0){}
	Mint(int x):x(x) {}
	void operator+= (Mint you){x+=you.x;if(x>=mod)x-=mod;}
	void operator-= (Mint you){x-=you.x;if(x<0)x+=mod;}
	void operator*= (Mint you){x=ll(x)*you.x%mod;}
	void operator/= (Mint you){x=ll(x)*Qpow(you.x,mod-2)%mod;}
	Mint Inv(){return Qpow(x,mod-2);}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t>=mod?t-mod:t;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t<0?t+mod:t;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}
Mint operator/ (Mint a,Mint b){return ll(a.x)*Qpow(b.x,mod-2)%mod;}

int row[MAXN][2],col[MAXN][2],rf[3],cf[3],cnt1,cnt2;
Mint pw[MAXN];
std::map<pii,bool>mp;
void Add(int x,int y,bool k)
{
		if(((x+y)&1)^k)
		{
			++cnt1;
			if(!row[x][0]++)
			{
				if(row[x][1])--rf[1],++rf[0];
				else --rf[2],++rf[1];
			}
			if(!col[y][0]++)
			{
				if(col[y][1])--cf[1],++cf[0];
				else --cf[2],++cf[1];
			}
		}
		else
		{
			++cnt2;
			if(!row[x][1]++)
			{
				if(row[x][0])--rf[1],++rf[0];
				else --rf[2],++rf[1];
			}
			if(!col[y][1]++)
			{
				if(col[y][0])--cf[1],++cf[0];
				else --cf[2],++cf[1];
			}
		}
}
void Del(int x,int y,bool k)
{
		if(((x+y)&1)^k)
		{
			--cnt1;
			if(!--row[x][0])
			{
				if(row[x][1])--rf[0],++rf[1];
				else --rf[1],++rf[2];
			}
			if(!--col[y][0])
			{
				if(col[y][1])--cf[0],++cf[1];
				else --cf[1],++cf[2];
			}
		}
		else
		{
			--cnt2;
			if(!--row[x][1])
			{
				if(row[x][0])--rf[0],++rf[1];
				else --rf[1],++rf[2];
			}
			if(!--col[y][1])
			{
				if(col[y][0])--cf[0],++cf[1];
				else --cf[1],++cf[2];
			}
		}
}
int main()
{
	int n=read(),m=read(),k=read();
	pw[0]=1;
	for(int i=1;i<=n+m;++i)pw[i]=pw[i-1]*2;
	cf[2]=m,rf[2]=n;
	for(int i=1;i<=k;++i)
	{
		int x=read(),y=read(),t=read();
		if(t==-1)
		{
			if(mp.count(pii(x,y)))Del(x,y,mp[pii(x,y)]),mp.erase(pii(x,y));
		}
		else if(t==0)
		{
			if(mp.count(pii(x,y)))Del(x,y,mp[pii(x,y)]);
			Add(x,y,mp[pii(x,y)]=0);
		}
		else
		{
			if(mp.count(pii(x,y)))Del(x,y,mp[pii(x,y)]);
			Add(x,y,mp[pii(x,y)]=1);
		}
		//printf("[%d,%d,%d] [%d,%d,%d] %d %d\n",rf[0],rf[1],rf[2],cf[0],cf[1],cf[2],cnt1,cnt2);
		Mint res=(rf[0]?0:pw[rf[2]])+(cf[0]?0:pw[cf[2]]);
		res=res-(!cnt1)-(!cnt2);
		printf("%d\n",res.x);
	}
	return 0;
}