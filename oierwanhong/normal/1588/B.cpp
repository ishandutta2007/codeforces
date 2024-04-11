#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
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
ll Query(int x)
{
	std::cout<<"? 1 "<<x<<std::endl;
	return read();
}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		ll all=Query(n);
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(Query(mid)==all)r=mid;
			else l=mid+1;
		}
		//fprintf(stderr,"L=%d\n",l);
		ll len=all-Query(l-1)+1;
		ll rest=all-len*(len-1)/2,pre=(1+sqrt(1+8*rest))/2;
		std::cout<<"! "<<l-len-pre+1<<" "<<l-len+1<<" "<<l<<std::endl;
	}
	return 0;
}