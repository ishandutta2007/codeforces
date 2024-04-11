#include <bits/stdc++.h>

using namespace std;

long long n,m,nn[1069][2],a[1069][2][169],sz[2],cr[2][169],sq[26],zs=0;
vector<long long> al[26];
bitset<26> spc,vtd,vtd2;

void no()
{
	cout<<"IMPOSSIBLE\n";
	exit(0);
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
		else if(vtd2[l])
		{
			no();
		}
	}
	vtd2[x]=0;
	sq[zs]=x;
	zs++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long i,j,r,p;
	string s;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>p;
		p++;
		for(j=1;j<=m;j++)
		{
			cin>>s;
			sz[0]=s.length();
			if(j==1)
			{
				nn[p][0]=sz[0];
			}
			if(j==m)
			{
				nn[p][1]=sz[0];
			}
			for(r=1;r<=sz[0];r++)
			{
				cr[0][r]=s[r-1]-'a';
				if(j==1)
				{
					a[p][0][r]=cr[0][r];
				}
				if(j==m)
				{
					a[p][1][r]=cr[0][r];
				}
				spc[cr[0][r]]=1;
			}
			if(j-1)
			{
				for(r=1;r<=min(sz[0],sz[1]);r++)
				{
					if(cr[1][r]!=cr[0][r])
					{
						al[cr[1][r]].push_back(cr[0][r]);
						r=-1;
						break;
					}
				}
				if(r!=-1&&sz[1]>sz[0])
				{
					no();
				}
			}
			for(r=1;r<=sz[0];r++)
			{
				cr[1][r]=cr[0][r];
			}
			sz[1]=sz[0];
		}
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=min(nn[i-1][1],nn[i][0]);j++)
		{
			if(a[i-1][1][j]!=a[i][0][j])
			{
				al[a[i-1][1][j]].push_back(a[i][0][j]);
				j=-1;
				break;
			}
		}
		if(j!=-1&&nn[i-1][1]>nn[i][0])
		{
			no();
		}
	}
	for(i=0;i<26;i++)
	{
		if(spc[i]&&!vtd[i])
		{
			dfs(i);
		}
	}
	for(i=zs-1;i+1;i--)
	{
		cout<<(char)(sq[i]+'a');
	}
	cout<<"\n";
}