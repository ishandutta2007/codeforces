#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 200011,B = 455;
pii a[MAXN];
struct FastModify
{
	int sum[MAXN/B+11],a[MAXN];
	void modify(int i,int k)
	{
		if(i>=200000)return;
		sum[(i-1)/B]+=k,a[i]+=k;
	}
	int Qsum(int n)
	{
		int bl=(n-1)/B,res=0;
		for(int I=0;I<bl;++I)res+=sum[I];
		for(int i=bl*B+1;i<=n;++i)res+=a[i];
		return res;
	}
}L;
int sum[511][511],lst[MAXN];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)a[i].first=read(),a[i].second=read();
	for(int i=1;i<=m;++i)
	{
		int op=read(),k=read(),T=i;
		if(op==2)op=-1,T=lst[k];
		else lst[k]=i;
		int x=a[k].first,y=a[k].second;
		if(x+y>=B)
		{
			for(int t=0;T+t*(x+y)<=m;++t)
				L.modify(T+t*(x+y)+x,op),L.modify(T+(t+1)*(x+y),-op);
		}
		else
		{
			int s=x+y;
			int st=(T+x)%s,ed=(T+x+y-1)%s;
			if(st<=ed)
				for(int k=st;k<=ed;++k)sum[s][k]+=op;
			else
			{
				for(int k=st;k<s;++k)sum[s][k]+=op;
				for(int k=0;k<=ed;++k)sum[s][k]+=op;
			}
		}
		int res=L.Qsum(i);
		//fprintf(stderr,"pre=%d\n",res);
		for(int r=1;r<B;++r)res+=sum[r][i%r];
		printf("%d\n",res);
	}
	return 0;
}