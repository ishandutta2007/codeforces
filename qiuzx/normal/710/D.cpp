//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
#define B 60000
using namespace std;
ll a1,b1,a2,b2,num[N];
ll calc(ll x)
{
	ll i,ans=0,mna=max((ll)0,(b2-b1+a1*INF+a1-1)/a1-INF),mxa=(x-b1+a1*INF)/a1-INF,md=((b2%a2)+a2)%a2;
	if(mna>mxa)
	{
		return 0;
	}
	if(a1>=B)
	{
		for(i=mna;i<=mxa;i++)
		{
			if((((a1*i+b1)%a2)+a2)%a2==md)
			{
				ans++;
			}
		}
		return ans;
	}
	memset(num,0,sizeof(num));
	for(i=0;i<a2;i++)
	{
		num[(((a1*i+b1)%a2)+a2)%a2]++;
	}
	while(mna%a2!=0&&mna<=mxa)
	{
		if((((a1*mna+b1)%a2)+a2)%a2==md)
		{
			ans++;
		}
		mna++;
	}
	while(mxa%a2!=a2-1&&mxa>=mna)
	{
		if((((a1*mxa+b1)%a2)+a2)%a2==md)
		{
			ans++;
		}
		mxa--;
	}
	return num[md]*((mxa-mna+1)/a2)+ans;
}
int main(){
	ll l,r;
	cin>>a1>>b1>>a2>>b2>>l>>r;
	if(a2>=B)
	{
		swap(a1,a2);
		swap(b1,b2);
	}
	cout<<calc(r)-calc(l-1)<<endl;
	return 0;
}