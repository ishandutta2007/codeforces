#include<bits/stdc++.h>
using namespace std;

const long long inf=1000000000000000ll;
int n,l[110],m[110],r[110],x,y,po[310],typ[310],cnt;
long long f[2][310][310];
pair<int,int> val[310];

int main()
{
	scanf("%d",&n),cnt=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d%d",&x,&y);
		l[i]=x-y,m[i]=x,r[i]=x+y;
		val[++cnt]=make_pair(l[i],i);
		val[++cnt]=make_pair(m[i],i+n);
		val[++cnt]=make_pair(r[i],i+2*n);
	}
	sort(val+1,val+1+cnt),val[0].first=val[1].first;
	for (int i=1; i<=cnt; i++)
	{
		if (val[i].second>2*n) r[val[i].second-2*n]=i,typ[i]=2,po[i]=val[i].second-2*n; else
		if (val[i].second>n) m[val[i].second-n]=i,typ[i]=1,po[i]=val[i].second-n; else 
		l[val[i].second]=i,typ[i]=0,po[i]=val[i].second;
	}
	for (int i=0; i<=cnt; i++)
		for (int j=0; j<=cnt; j++) f[0][i][j]=-inf;
	f[0][0][0]=0,x=1,y=0;
	for (int i=1,len; i<=cnt; i++)
	{
		x^=1,y^=1,len=val[i].first-val[i-1].first;
		for (int j=0; j<=cnt; j++)
			for (int k=0; k<=cnt; k++) f[y][j][k]=-inf;
		if (typ[i]==0)
		{
			f[y][i][0]=f[x][0][0];
			f[y][0][0]=f[x][0][0];
			for (int j=1; j<i; j++)
			{
				f[y][j][0]=f[x][j][0]+len;
				for (int k=i; k<=cnt; k++)
					f[y][j][k]=f[x][j][k]+len;
			}
		} else
		if (typ[i]==1)
		{
			f[y][i][r[po[i]]]=f[x][0][0];
			for (int j=1; j<i; j++)
				if (j==l[po[i]])
				{
					for (int k=1; k<=n; k++)
						if (m[k]<i&&r[k]>i) f[y][m[k]][r[k]]=max(f[y][m[k]][r[k]],f[x][j][r[k]]+len);
						else if (l[k]<i&&m[k]>i) f[y][l[k]][0]=max(f[y][l[k]][0],f[x][j][0]+len);
					f[y][0][0]=max(f[y][0][0],f[x][j][0]+len);
				} else
				{
					for (int k=0; k<=cnt; k++)
						f[y][j][max(r[po[i]],k)]=max(f[y][j][max(r[po[i]],k)],f[x][j][k]+len);
				}
		} else
		{
			f[y][0][0]=f[x][0][0];
			for (int j=1; j<i; j++)
				if (j==m[po[i]])
				{
					for (int k=1; k<=n; k++)
						if (m[k]<i&&r[k]>i) f[y][m[k]][r[k]]=max(f[y][m[k]][r[k]],f[x][j][r[k]]+len);
						else if (l[k]<i&&m[k]>i) f[y][l[k]][0]=max(f[y][l[k]][0],f[x][j][i]+len);
					f[y][0][0]=max(f[y][0][0],f[x][j][i]+len);
				} else
				{
					for (int k=0; k<=cnt; k++)
						if (k!=i) f[y][j][k]=max(f[y][j][k],f[x][j][k]+len);
						else f[y][j][0]=max(f[y][j][0],f[x][j][k]+len);
				}
		}
	}
	return printf("%I64d\n",f[y][0][0]),0;
}