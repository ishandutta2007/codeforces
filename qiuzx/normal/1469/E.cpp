#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll int
#define N 1000010
using namespace std;
char buf[N];
ll n,k,on_num[N];
set<ll> badmask;
string s;
void print(ll x)
{
	ll i;
	for(i=0;i<k-min(k,20);i++)
	{
		printf("0");
	}
	for(i=min(k,20)-1;i>=0;i--)
	{
		printf("%d",(x&(1<<i))!=0);
	}
	puts("");
	return;
}
int main(){
	ll q,i,mask;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",&buf);
		s=buf;
		on_num[0]=0;
		for(i=0;i<n;i++)
		{
			on_num[i+1]=on_num[i]+(s[i]-'0');
		}
		mask=0;
		badmask.clear();
		for(i=k-min(k,20);i<k;i++)
		{
			mask<<=1;
			mask|=('1'-s[i]);
		}
		if(on_num[k-min(k,20)]-on_num[0]==k-min(k,20))
		{
			badmask.insert(mask);
		}
		for(i=k;i<n;i++)
		{
			mask<<=1;
			mask&=((1<<min(k,20))-1);
			mask|=('1'-s[i]);
			if(on_num[i+1-min(k,20)]-on_num[i+1-k]==k-min(k,20))
			{
				badmask.insert(mask);
			}
		}
		for(i=0;i<(1<<min(k,20));i++)
		{
			if(badmask.find(i)!=badmask.end())
			{
				continue;
			}
			break;
		}
		if(i==(1<<min(k,20)))
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			print(i);
		}
	}
	return 0;
}