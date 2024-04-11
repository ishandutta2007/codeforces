#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<iostream>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 1005

using namespace std;

pair<int,int> way[3];

int i,j,m,n,a[N][N],g[5],k,b[N][N];

char c[N*N];

void Main()
{
	for (i=0;i<3;++i) way[i]=mk(0,i);
	scanf("%d%d",&n,&m);
	for (i=0;i<n;++i)
		for (j=0;j<n;++j) scanf("%d",&a[i][j]);
	scanf("%s",c);
	for (i=0;i<m;++i)
	{
		if (c[i]=='L') way[1].fi=(way[1].fi+n-1)%n;
		if (c[i]=='R') way[1].fi=(way[1].fi+1)%n;
		if (c[i]=='U') way[0].fi=(way[0].fi+n-1)%n;
		if (c[i]=='D') way[0].fi=(way[0].fi+1)%n;
		if (c[i]=='I') swap(way[1],way[2]);
		if (c[i]=='C') swap(way[0],way[2]);
	}
	for (i=0;i<n;++i)
		for (j=0;j<n;++j)
		{
			for (k=0;k<3;++k)
			{
				if (way[k].se==0) g[k]=i;
				if (way[k].se==1) g[k]=j;
				if (way[k].se==2) g[k]=a[i][j]-1;
				g[k]=(g[k]+way[k].fi)%n;
			}
			b[g[0]][g[1]]=g[2]+1;
		}
	for (i=0;i<n;++i,puts(""))
		for (j=0;j<n;++j)
			printf("%d ",b[i][j]);
	puts("");
}

int main()
{
	int T; scanf("%d",&T);
	for (;T--;) Main(); 
}