#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
typedef long long ll;
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
std::set<pii>s;
std::set<pii>a[8],b[8];
const int mx[]={0,1,1,1,0,-1,-1,-1},my[]={1,1,0,-1,-1,-1,0,1};
int main()
{
	int n=read();
	a[0].insert(pii(0,-1));
	while(n--)
	{
		int t=read();
		for(int i=0;i<8;++i)
		{
			for(auto E:a[i])
			{
				int x=E.first,y=E.second;
				for(int k=1;k<=t;++k)x+=mx[i],y+=my[i],s.insert(pii(x,y));
				b[(i+1)%8].insert(pii(x,y));
				b[(i-1+8)%8].insert(pii(x,y));
			}
		}
		for(int i=0;i<8;++i)b[i].swap(a[i]),b[i].clear();
	}
	printf("%d\n",int(s.size()));
	return 0;
}