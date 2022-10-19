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
string s,ans="";
ll tot[80],msk[N],sum[80],cnt[10],m;
bool check(ll id)
{
	ll i;
	for(i=0;i<64;i++)
	{
		if(tot[i]>sum[i])
		{
			return false;
		}
	}
	return true;
}
int main(){
	string chs;
	ll i,j,x,mask;
	cin>>s>>m;
	for(i=0;i<s.size();i++)
	{
		cnt[s[i]-'a']++;
		msk[i]=63;
	}
	for(i=0;i<m;i++)
	{
		cin>>x>>chs;
		x--;
		mask=0;
		for(j=0;j<chs.size();j++)
		{
			mask|=(1<<(chs[j]-'a'));
		}
		msk[x]=mask;
	}
	for(i=0;i<s.size();i++)
	{
		mask=msk[i];
		for(j=0;j<64;j++)
		{
			if((j&mask)==mask)
			{
				tot[j]++;
			}
		}
	}
	for(i=0;i<64;i++)
	{
		for(j=0;j<6;j++)
		{
			if(i&(1<<j))
			{
				sum[i]+=cnt[j];
			}
		}
	}
	for(i=0;i<s.size();i++)
	{
		for(j=0;j<6;j++)
		{
			if(!((1<<j)&msk[i]))
			{
				continue;
			}
			for(x=0;x<64;x++)
			{
				if((x&msk[i])==msk[i])
				{
					tot[x]--;
				}
				if(x&(1<<j))
				{
					sum[x]--;
				}
			}
			if(check(j))
			{
				ans+=(char)('a'+j);
				cnt[j]--;
				j=-1;
				break;
			}
			for(x=0;x<64;x++)
			{
				if((x&msk[i])==msk[i])
				{
					tot[x]++;
				}
				if(x&(1<<j))
				{
					sum[x]++;
				}
			}
		}
		if(j!=-1)
		{
			puts("Impossible");
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}