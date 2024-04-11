#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,fq[2][5069],ps[2][5069],in[5069];
bitset<5069> aa;
vector<long long> v[5069];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long i,j,ii,k,l,sz,ls,u,sm,mx=0;
	string s;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			aa[j]=s[j-1]-'0';
		}
		ls=0;
		for(j=1;j<=m;j++)
		{
			if(!aa[j])
			{
				ls=j;
			}
			else if(!aa[j+1])
			{
				nn++;
				fq[0][ls+1]++;
				fq[1][j]++;
				v[j].push_back(ls+1);
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		u=ii*2-1;
		for(i=m-(m-1)*ii;i!=(m+1)*ii;i+=u)
		{
			ps[ii][i]=ps[ii][i-u]+fq[ii][i];
		}
	}
	for(i=1;i<=m;i++)
	{
		sm=0;
		for(j=i;j;j--)
		{
			sm+=in[j+1];
			k=nn-ps[0][j+1]-ps[1][i-1]+sm;
			mx=max(mx,k*(i-j+1));
		}
		sz=v[i].size();
		for(j=0;j<sz;j++)
		{
			in[v[i][j]]++;
		}
	}
	cout<<mx<<"\n";
}