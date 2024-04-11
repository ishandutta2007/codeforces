//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef long long ll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
using namespace std;
const ll mid=1<<7;
int main()
{
	cout<<"? ";
	for(ll i=1;i<=100;++i)cout<<i*mid<<" ";
	cout<<endl;
	fflush(stdout);
	ll a;cin>>a;a%=mid;
	cout<<"? ";
	for(ll i=1;i<=100;++i)cout<<i<<" ";
	cout<<endl;
	fflush(stdout);
	ll b;cin>>b;b/=mid;
	cout<<"! "<<b*mid+a<<endl;
	return 0;
}