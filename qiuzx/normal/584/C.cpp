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
char buf[N],ans[N];
vector<ll> sm,dif;
string s1,s2;
ll n,t;
void cons(ll b,ll a)
{
	ll i,x;
	char c;
	for(i=0;i<b;i++)
	{
		for(c='a';c<='z';c++)
		{
			if(c!=s1[sm[i]])
			{
				ans[sm[i]]=c;
				break;
			}
		}
	}
	for(i=b;i<sm.size();i++)
	{
		ans[sm[i]]=s1[sm[i]];
	}
	for(i=0;i<a;i++)
	{
		for(c='a';c<='z';c++)
		{
			if(c!=s1[dif[i]]&&c!=s2[dif[i]])
			{
				ans[dif[i]]=c;
				break;
			}
		}
	}
	for(i=a;i<a+(dif.size()-a)/2;i++)
	{
		ans[dif[i]]=s1[dif[i]];
	}
	for(i=a+(dif.size()-a)/2;i<dif.size();i++)
	{
		ans[dif[i]]=s2[dif[i]];
	}
	return;
}
int main(){
	ll i,j;
	char c;
	scanf("%lld%lld",&n,&t);
	scanf("%s",&buf);
	s1=buf;
	scanf("%s",&buf);
	s2=buf;
	for(i=0;i<n;i++)
	{
		if(s1[i]==s2[i])
		{
			sm.push_back(i);
		}
		else
		{
			dif.push_back(i);
		}
	}
	for(i=0;i<=sm.size();i++)
	{
		j=2*t-dif.size()-2*i;
		if(0<=j&&j<=dif.size())
		{
			cons(i,j);
			i=-1;
			break;
		}
	}
	if(i!=-1)
	{
		puts("-1");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		printf("%c",ans[i]);
	}
	puts("");
	return 0;
}