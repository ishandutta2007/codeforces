#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef unsigned un;
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
std::string a[555],b[555];
int main()
{
	int n=read(),m=read();
	for(int i=0;i<n;++i)std::cin>>a[i];
	for(int i=0;i<m;++i)std::cin>>b[i];
	int q=read();
	while(q--)
	{
		int x=read()-1;
		std::cout<<a[x%n]<<b[x%m]<<std::endl;
	}
	return 0;
}