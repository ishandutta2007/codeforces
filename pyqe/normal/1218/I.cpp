#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m=0,zs=0;
bitset<2069> a[2069],d;
pair<long long,vector<pair<long long,long long>>> mnv;
vector<pair<long long,long long>> sq,v;
string ky[2]={"row","col"};

int main()
{
	long long i,j,ii,c,ls=0,sz;
	string s;
	bool bad;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<n;i++)
		{
			cin>>s;
			for(j=0;j<n;j++)
			{
				a[i][j]=a[i][j]^(s[j]-'0');
			}
		}
	}
	cin>>s;
	for(i=0;i<n;i++)
	{
		d[i]=s[i]-'0';
		m+=d[i];
		if(d[i])
		{
			ls=i;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(!d[i]&&!d[j]&&a[i][j])
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<n;i++)
		{
			if(!d[i])
			{
				c=0;
				for(j=0;j<n;j++)
				{
					if(ii)
					{
						swap(i,j);
					}
					c+=a[i][j];
					if(ii)
					{
						swap(i,j);
					}
				}
				if(c&&c<m)
				{
					printf("-1\n");
					return 0;
				}
				if(c&&c==m)
				{
					sq.push_back({ii,i});
					zs++;
				}
			}
		}
	}
	mnv.fr=1e18;
	for(ii=0;ii<2;ii++)
	{
		bad=0;
		v.clear();
		sz=0;
		if(ii)
		{
			v.push_back({0,ls});
			sz++;
		}
		for(i=0;i<n;i++)
		{
			if(d[i]&&a[ls][i]^ii)
			{
				v.push_back({1,i});
				sz++;
			}
		}
		for(i=0;i<ls;i++)
		{
			if(d[i])
			{
				c=0;
				for(j=0;j<n;j++)
				{
					if(d[j])
					{
						c+=a[i][j]^a[ls][j]^ii;
					}
				}
				if(c&&c<m)
				{
					bad=1;
					break;
				}
				if(c&&c==m)
				{
					v.push_back({0,i});
					sz++;
				}
			}
		}
		if(!bad)
		{
			mnv=min(mnv,{sz,v});
		}
	}
	if(mnv.fr==1000000000000000000)
	{
		printf("-1\n");
	}
	else
	{
		for(i=0;i<mnv.fr;i++)
		{
			sq.push_back(mnv.sc[i]);
			zs++;
		}
		printf("%lld\n",zs);
		for(i=0;i<zs;i++)
		{
			printf("%s %lld\n",ky[sq[i].fr].c_str(),sq[i].sc);
		}
	}
}