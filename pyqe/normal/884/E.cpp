#include <bits/stdc++.h>

using namespace std;

const int mm=1ll<<14;
int n,m,dsu[mm+1],pst[mm+1];
bitset<mm+1> ca;

int fd(int x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,j,r,k,z=0;
	string s;
	
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>s;
		for(j=1;j<=m/4;j++)
		{
			k=s[j-1]-'0';
			if(k<0||k>9)
			{
				k=s[j-1]-'A'+10;
			}
			for(r=0;r<4;r++)
			{
				ca[(j<<2)-r]=k>>r&1;
			}
		}
		for(j=1;j<=m;j++)
		{
			pst[j]=0;
		}
		for(j=1;j<=m;j++)
		{
			z+=ca[j];
			if(!ca[j])
			{
				dsu[j]=0;
			}
			else if(dsu[j])
			{
				z--;
			}
			pst[dsu[j]]=j;
		}
		for(j=1;j<=m;j++)
		{
			if(dsu[j])
			{
				dsu[j]=pst[dsu[j]];
			}
			else if(ca[j])
			{
				dsu[j]=j;
			}
		}
		for(j=2;j<=m;j++)
		{
			if(dsu[j]&&dsu[j-1]&&fd(j-1)!=fd(j))
			{
				z--;
				dsu[fd(j-1)]=fd(j);
			}
		}
		for(j=1;j<=m;j++)
		{
			fd(j);
		}
	}
	cout<<z<<"\n";
}