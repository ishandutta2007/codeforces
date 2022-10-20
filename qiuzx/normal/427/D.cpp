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
#define N 15010
using namespace std;
string s1,s2,suf;
ll z[N],z1[N],z2[N];
vector<ll> vs;
void runz(string s)
{
	ll i,j,l,r;
	memset(z,0,sizeof(z));
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
	return;
}
int main(){
	ll i,j,k,l,r,ans=LINF,mx1,mx2;
	cin>>s1>>s2;
	suf="#";
	runz(s1);
	for(i=0;i<s1.size();i++)
	{
		z1[i]=z[i];
	}
	runz(s2);
	for(i=0;i<s2.size();i++)
	{
		z2[i]=z[i];
	}
	for(i=s1.size()-1;i>=0;i--)
	{
		suf=s1[i]+suf;
		runz(suf+s2);
		for(j=0;j<suf.size();j++)
		{
			if(suf[j]=='#')
			{
				break;
			}
		}
		j++;
		mx1=mx2=-1;
		for(k=0;k<s2.size();k++)
		{
			if(z[k+j]>mx1)
			{
				mx2=mx1;
				mx1=z[k+j];
			}
			else if(z[k+j]>mx2)
			{
				mx2=z[k+j];
			}
		}
		if(mx2==-1)
		{
			mx2=mx1-1;
		}
		l=mx2+1;
		r=mx1;
		runz(suf+s1);
		mx1=mx2=-1;
		for(k=0;k<s1.size();k++)
		{
			if(z[k+j]>mx1)
			{
				mx2=mx1;
				mx1=z[k+j];
			}
			else if(z[k+j]>mx2)
			{
				mx2=z[k+j];
			}
		}
		if(mx2==-1)
		{
			mx2=mx1-1;
		}
		mx2++;
		if(max(l,mx2)>min(mx1,r))
		{
			continue;
		}
		ans=min(ans,max(l,mx2));
	}
	if(ans<INF)
	{
		cout<<ans<<endl;
	}
	else
	{
		puts("-1");
	}
	return 0;
}