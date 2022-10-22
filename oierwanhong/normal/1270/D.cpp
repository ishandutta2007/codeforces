#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void umax(int& a,int t){if(a<t)a=t;}
bool umin(ll& a,ll t){if(a>t)return a=t,1;return 0;}
ll abs(ll x){return x>0?x:-x;}

/**********/
int main()
{
	int n,k,res=1;
	std::cin>>n>>k;
	if(k==1){std::cout<<"! 1"<<std::endl;return 0;}
	if(k==2)
	{
		std::cout<<"? 1 2"<<std::endl;
		int p1,v1,p2,v2,p,v;std::cin>>p1>>v1;
		std::cout<<"?";
		if(p1==1)std::cout<<" 2 3"<<std::endl;
		else std::cout<<" 1 3"<<std::endl;
		std::cin>>p2>>v2;
		std::cout<<"? "<<p1<<" "<<p2<<std::endl;
		std::cin>>p>>v;
		if(v==min(v1,v2))std::cout<<"! 1"<<std::endl;
		else std::cout<<"! 2"<<std::endl;
		return 0;
	}
	std::cout<<"?";
	for(int i=1;i<=k;++i)std::cout<<" "<<i;
	std::cout<<std::endl;
	int p1,v1,p2,v2;
	std::cin>>p1>>v1;
	std::cout<<"?";
	for(int i=1;i<=k+1;++i)
		if(p1!=i)std::cout<<" "<<i;
	std::cout<<std::endl;
	std::cin>>p2>>v2;
	int pos=1;
	for(int w=1;w<=k-1;++w)
	{
		while(pos==p1||pos==p2)++pos;
		std::cout<<"?";
		for(int i=1;i<=k+1;++i)
			if(pos!=i)std::cout<<" "<<i;
		std::cout<<std::endl;
		int p,v;std::cin>>p>>v;
		if(v>v2)++res;
		else if(v<v2);
		else if(v1<v2)++res;
		++pos;
	}
	std::cout<<"! "<<res<<std::endl;
	return 0;
}