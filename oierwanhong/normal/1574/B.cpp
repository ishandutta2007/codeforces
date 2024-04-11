#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned un;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
int main()
{
	int task=read();
	while(task--)
	{
		std::vector<int> a;
		a.push_back(read()),a.push_back(read()),a.push_back(read());
		int m=read();
		int sum=a[0]+a[1]+a[2];
		if(m>sum-3){puts("NO");continue;}
		std::sort(a.begin(),a.end());
		int lim=(a[2]-1>a[0]+a[1]?a[2]-1-a[0]-a[1]:0);
		puts(m<lim?"NO":"YES");
	}
	return 0;
}