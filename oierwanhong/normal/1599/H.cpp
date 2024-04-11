#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
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
const int LIM = 1e9;
int Ask(int x,int y)
{
	std::cout<<"? "<<x<<" "<<y<<std::endl;
	int l=read();
	if(l==-1)exit(0);
	return l;
}
int main()
{
	int fl=Ask(1,1),fr=Ask(LIM,1);
	int l=1,r=LIM;
	int pl=fl,pr=fr;
	while(l+1<r)
	{
		int mid=(l+r)>>1,f=Ask(mid,1);
		if(pl-(mid-l)==f)l=mid,pl=f;
		else if(pr-(r-mid)==f)r=mid,pr=f;
		else
		{
			l=mid-1,pl=Ask(l,1);
			r=mid,pr=Ask(r,1);
			break;
		}
	}
	int y=min(pl,pr)+1;
	int up=Ask(LIM,LIM);
	printf("! %d %d ",1+(fl-(y-1)),y);
	int rw=fr-(y-1);
	int rb=LIM-(fr-(y-1));
	printf("%d %d\n",rb,LIM-(up-rw));
	return 0;
}