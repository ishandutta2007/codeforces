#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 100010
using namespace std;
ll z[N],app[N];
string s;
vector<pair<ll,ll> > ans;
void getz(string s)
{
	ll i,l,r,j;
	z[0]=s.size();
	l=0;
	r=0;
	for(i=1;i<s.size();++i)
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
		}
		else
		{
			if(z[i-l]<r-i+1)
			{
				z[i]=z[i-l];
			}
			else
			{
				for(j=r;j<s.size();j++)
				{
					if(s[j]!=s[j-i])
					{
						break;
					}
				}
				z[i]=j-i;
			}
		}
		if(r<i+z[i]-1)
		{
			r=i+z[i]-1;
			l=i;
		}
	}
	return;
}
int main(){
	ll i;
	cin>>s;
	getz(s);
	for(i=0;i<s.size();i++)
	{
		app[z[i]]++;
	}
	for(i=s.size();i>0;i--)
	{
		app[i-1]+=app[i];
	}
	for(i=0;i<s.size();i++)
	{
		if(z[i]==s.size()-i)
		{
			ans.push_back(make_pair(z[i],app[z[i]]));
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld %lld\n",ans[i].F,ans[i].S);
	}
	return 0;
}