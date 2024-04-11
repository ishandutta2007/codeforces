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
#define N 200010
using namespace std;
string s;
ll ans;
char buf[N];
int main(){
	ll t,i,num;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",&buf);
		s=buf;
		ans=0;
		num=0;
		for(i=0;i<s.size();i++)
		{
			if(s[i]==')')
			{
				if(num>0)
				{
					num--;
					ans++;
				}
			}
			if(s[i]=='(')
			{
				num++;
			}
		}
		num=0;
		for(i=0;i<s.size();i++)
		{
			if(s[i]==']')
			{
				if(num>0)
				{
					num--;
					ans++;
				}
			}
			if(s[i]=='[')
			{
				num++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}