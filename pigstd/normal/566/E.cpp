#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e3+10;
int n,f=1,v[M],w[M],cnt;
bitset<M>e[M],a[M],b[M];

int main()
{
	n=read();
	if (n==2){puts("1 2");return 0;}
	for (int i=1;i<=n;i++)
	{
		int k=read();
		if (k!=n)f=0;
		for (int j=1;j<=k;j++)
			a[i][read()]=1;
	}
	if (f)
	{
		for (int i=1;i<n;i++)
			cout<<i<<' '<<n<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1+i;j<=n;j++)
		{
			bitset<M>k=a[i]&a[j];
			if (k.count()!=2)continue;
			int x=k._Find_first(),y=k._Find_next(x);
			if (e[x][y]!=1)cout<<x<<' '<<y<<endl;
			e[x][y]=e[y][x]=1;
			if (!v[x])v[x]=1,cnt++;
			if (!v[y])v[y]=1,cnt++;
		}
//	for (int i=1;i<=n;i++)
//		if (!v[i])cout<<i<<' ';cout<<cnt<<endl;
	for (int i=1;i<=n;i++)
		if (!v[i])
		{
			int maxn=1e9,p=-1;
			for (int j=1;j<=n;j++)
				if (!w[j]&&a[j][i])
				{
					int c=a[j].count();
					if (c<maxn)maxn=c,p=j;
				}
			b[i]=a[p],w[p]=1;
		}
		else e[i][i]=1;
	if (cnt==2)
	{
		int p1,p2;
		for (int i=1;i<=n;i++)
			if (v[i])p1=i;
		for (int i=n;i>=1;i--)
			if (v[i])p2=i;
		for (int i=1;i<=n;i++)
			if (a[i].count()!=n)
			{
				for (int j=1;j<=n;j++)
					if (!v[j])
					{
						if (a[i][j])cout<<j<<' '<<p1<<endl;
						else cout<<j<<' '<<p2<<endl;
//						cout<<i<<' '<<j<<' '<<a[i][j]<<endl;
					}
				break;
			}
//		cout<<endl<<p1<<' '<<p2<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)
		if (!v[i])
		{
			for (int j=1;j<=n;j++)
				if (!v[j])b[i][j]=0; 
			for (int j=1;j<=n;j++)
				if (v[j]&&b[i]==e[j])
					{cout<<i<<' '<<j<<endl;break;}
		}
	return 0;
}