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
#define ll long long
#define N 1000010
using namespace std;
ll n,pos[N];
string s;
char buf[N];
int main(){
	ll i,q,p;
	char c;
	scanf("%lld",&n);
	scanf("%s",&buf);
	s=buf;
	for(i=(1<<(n+1))-1;i>=(1<<n);i--)
	{
		pos[i]=1;
	}
	for(i=(1<<n)-1;i>0;i--)
	{
		if(s[(1<<n)-i-1]=='0')
		{
			pos[i]=pos[i*2+1];
		}
		else if(s[(1<<n)-i-1]=='1')
		{
			pos[i]=pos[i*2];
		}
		else
		{
			pos[i]=pos[i*2]+pos[i*2+1];
		}
	}
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld %c",&p,&c);
		p--;
		s[p]=c;
		p=(1<<n)-p-1;
		while(p>0)
		{
			if(s[(1<<n)-p-1]=='0')
			{
				pos[p]=pos[p*2+1];
			}
			else if(s[(1<<n)-p-1]=='1')
			{
				pos[p]=pos[p*2];
			}
			else
			{
				pos[p]=pos[p*2]+pos[p*2+1];
			}
			p>>=1;
		}
		printf("%lld\n",pos[1]);
	}
	return 0;
}