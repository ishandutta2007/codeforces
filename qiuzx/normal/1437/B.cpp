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
#define N 100010
using namespace std;
ll n;
char buf[N];
string s;
int main(){
	ll t,i,num1,num2;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%s",&n,&buf);
		s=buf;
		num1=num2=0;
		for(i=1;i<n;i++)
		{
			if(s[i]==s[i-1])
			{
				if(s[i]=='1')
				{
					num1++;
				}
				else
				{
					num2++;
				}
			}
		}
		printf("%lld\n",max(num1,num2));
	}
	return 0;
}