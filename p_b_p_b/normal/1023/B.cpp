#include<bits/stdc++.h>
using namespace std;
struct FastIO
{
    inline FastIO& operator>>(long long& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
}read;
void file()
{
	#ifndef ONLINE_JUDGE
	freopen("a.txt","r",stdin);
	#endif
}
typedef long long ll;
int main()
{
	ll n,k;
	read>>n>>k;
	ll x=k/2ll;
	if (k%2ll==0)
	{
		ll y=max(min(x-1,n-x),0ll);
		printf("%I64d",y);
	}
	else
	{
		ll y=max(min(x,n-x),0ll);
		printf("%I64d",y);
	}
}