#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
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
int main()
{
	std::string str;
	std::cin>>str;
	int cnt=0;
	for(auto x:str)
		if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||(x>='0'&&x<='9'&&(x-'0')%2==1))++cnt;
	std::cout<<cnt<<std::endl;
	return 0;
}