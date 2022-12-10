#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<iostream>
#include<vector>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 1005

using namespace std;

int A[105][105],n,m,i,j,k; 

char c[105];

struct Node{
	int x1,y1,x2,y2,x3,y3;
};

Node Base[4];

vector<Node>ans;

void Workn()
{
	int i;
	for (i=1;i<=m-1;++i)
		if (A[n][i]==1)
		{
			if (A[n][i+1]==0) ans.pb((Node){n,i,n-1,i,n-1,i+1}),A[n][i]^=1,A[n-1][i]^=1,A[n-1][i+1]^=1;
			else ans.pb((Node){n,i,n,i+1,n-1,i}),A[n][i]^=1,A[n][i+1]^=1,A[n-1][i]^=1;
		}
	if (A[n][m]==1) ans.pb((Node){n,m,n-1,m-1,n-1,m}),A[n][m]^=1,A[n-1][m-1]^=1,A[n-1][m]^=1;
	--n;
}

void Workm()
{
	int i;
	for (i=1;i<=n-1;++i)
		if (A[i][m]==1)
		{
			if (A[i+1][m]==0) ans.pb((Node){i,m,i,m-1,i+1,m-1}),A[i][m]^=1,A[i][m-1]^=1,A[i+1][m-1]^=1;
			else ans.pb((Node){i,m,i+1,m,i,m-1}),A[i][m]^=1,A[i+1][m]^=1,A[i][m-1]^=1;
		}
	if (A[n][m]==1) ans.pb((Node){n,m,n-1,m-1,n,m-1}),A[n][m]^=1,A[n-1][m-1]^=1,A[n][m-1]^=1;
	--m;
}

void Doit()
{
	for (i=0;i<16;++i)
	{
			int W[3][3]={0};
			for (j=0;j<4;++j)
				if ((i>>j)&1)
				{
					W[Base[j].x1][Base[j].y1]^=1;
					W[Base[j].x2][Base[j].y2]^=1;
					W[Base[j].x3][Base[j].y3]^=1;
				}
			int flag=0;
			for (j=1;j<=2;++j)
				for (k=1;k<=2;++k)
					if (W[j][k]!=A[j][k]) flag=1;
			if (!flag) break;
	}
	for (j=0;j<4;++j)
		if ((i>>j)&1) ans.pb(Base[j]);
}

int main()
{
		int T;
		scanf("%d",&T);
		Base[0]=(Node){1,1,1,2,2,1};
		Base[1]=(Node){1,1,1,2,2,2};
		Base[2]=(Node){1,1,2,1,2,2};
		Base[3]=(Node){1,2,2,1,2,2}; 
		for (;T--;)
		{
			scanf("%d%d",&n,&m);
			for (i=1;i<=n;++i)
			{
				scanf("%s",c+1);
				for (j=1;j<=m;++j) A[i][j]=c[j]-'0';
			}
			ans.clear();
			while (n>2||m>2) if (n>2) Workn(); else Workm();
			Doit();
			printf("%d\n",ans.size());
			for (i=0;i<ans.size();++i) printf("%d %d %d %d %d %d\n",ans[i].x1,ans[i].y1,ans[i].x2,ans[i].y2,ans[i].x3,ans[i].y3); 
		}
}