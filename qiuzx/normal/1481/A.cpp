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
using namespace std;
ll x,y;
char buf[100010];
string s;
int main(){
	ll t,i,u,d,l,r;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&x,&y);
		scanf("%s",&buf);
		s=buf;
		u=d=l=r=0;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='U')
			{
				u++;
			}
			else if(s[i]=='R')
			{
				r++;
			}
			else if(s[i]=='D')
			{
				d++;
			}
			else
			{
				l++;
			}
		}
		if((x>=0&&r>=x)||(x<=0&&l>=(-x)))
		{
			if((y>=0&&u>=y)||(y<=0&&d>=(-y)))
			{
				puts("YES");
				continue;
			}
		}
		puts("NO");
	}
	return 0;
}