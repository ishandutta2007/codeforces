#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned long long ull;
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
int abs(int x){return x>0?x:-x;}
/**********/
const int MAXN = 100011;
int And(int i,int j)
{
	std::cout<<"and "<<i<<" "<<j<<std::endl;
	return read();
}
int Or(int i,int j)
{
	std::cout<<"or "<<i<<" "<<j<<std::endl;
	return read();
}
int a[MAXN];
int main()
{
	int n=read(),k=read();
	int to12=Or(1,2),ta12=And(1,2),to23=Or(2,3),ta23=And(2,3),to13=Or(1,3),ta13=And(1,3);
	for(int x=0;x<=30;++x)
	{
		bool O12=to12>>x&1,A12=ta12>>x&1;
		bool O23=to23>>x&1,A23=ta23>>x&1;
		bool O13=to13>>x&1,A13=ta13>>x&1;
		if(A12^O12)
		{
			if(A23^O23)
			{
				bool q=A13;
				a[1]|=q<<x,a[3]|=q<<x,a[2]|=(!q)<<x;
			}
			else
			{
				bool q=A23;
				a[2]|=q<<x,a[3]|=q<<x,a[1]|=(!q)<<x;
			}
		}
		else
		{
			bool q=A12;
			a[1]|=q<<x,a[2]|=q<<x;
			if(A23^O23)a[3]|=(!q)<<x;
			else a[3]|=q<<x;
		}
	}
	for(int i=4;i<=n;++i)
	{
		int A=And(1,i),O=Or(1,i);
		a[i]=a[1]^(A^O);
	}
	std::sort(a+1,a+n+1);
	std::cout<<"finish "<<a[k]<<std::endl;
	return 0;
}