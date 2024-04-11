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
string s;
ll z[N],mx=0;
int main(){
	ll i,j,l,r;
	memset(z,0,sizeof(z));
	cin>>s;
	l=r=0;
	z[0]=s.size();
	for(i=1;i<s.size();i++)
	{
		if(i>r)
		{
			for(j=i;j<s.size();j++)
			{
				if(s[j]!=s[j-i])
				{
					break;
				}
			}
			z[i]=j-i;
			l=i;
			r=j;
		}
		else if(i+z[i-l]>=r)
		{
			for(j=r;j<s.size();j++)
			{
				if(s[j]!=s[j-i])
				{
					break;
				}
			}
			z[i]=j-i;
			l=i;
			r=j;
		}
		else
		{
			z[i]=z[i-l];
		}
	}
	for(i=1;i<s.size();i++)
	{
		if(i+z[i]==s.size())
		{
			if(z[i]<=mx)
			{
				for(j=i;j<s.size();j++)
				{
					cout<<s[j];
				}
				puts("");
				return 0;
			}
		}
		mx=max(mx,z[i]);
	}
	puts("Just a legend");
	return 0;
}