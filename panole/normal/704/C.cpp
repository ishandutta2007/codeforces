#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int f[100010][2][2][2],val[100010],Ans,ansf[2],Ansf[2],n,m,cnt,hd[100010],k,x,y,fx,fy,q[100010],l,r,nwf[2];
struct node{int to,next,fx,fy;}e[200010];
bool bo[100010];

void addedge(int x,int y,int fx,int fy)
{
	e[++cnt]=(node){y,hd[x],fx,fy},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y],fy,fx},hd[y]=cnt;
}

void add(int &x,int y) {x=(x+y>=mod?x+y-mod:x+y);}

int calc(int x,int y,int fx,int fy)
{
	if (fx==-1) x^=1;
	if (fy==-1) y^=1;
	return (x|y);
}

int dfs(int x,int la,int rt)
{
	int vf[2]={0,0};
	if (val[x]==1) vf[1]=1; else
	if (val[x]==-1) vf[0]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to==la)
		{
			for (int j=0; j<2; j++)
				for (int k=0; k<2; k++)
					for (int l=0; l<2; l++)
						for (int m=0; m<2; m++)
							add(f[x][m][k][calc(m,j,e[i].fx,e[i].fy)^vf[m]^l],f[la][j][k][l]);
			break;
		}
	bool bo=0;
	for (int i=hd[x]; i; i=e[i].next)
		if (!bo&&e[i].to==la) bo=1; else
		if (e[i].to==rt)
		{
			for (int j=0; j<2; j++)
				for (int k=0; k<2; k++)
					if (calc(j,k,e[i].fx,e[i].fy)) swap(f[x][j][k][0],f[x][j][k][1]);
			return x;
		} else return dfs(e[i].to,x,rt);
	return x;
}

int main()
{
	scanf("%d%d",&m,&n),Ans=1;
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&k,&x);
		if (k==2) 
		{
			scanf("%d",&y);
			if (x==y) k--;
		}
		fx=(x<0?(x=-x,-1):1);
		fy=(y<0?(y=-y,-1):1);
		if (k==1)
		{
			if (val[x])
			{
				if (val[x]!=fx) Ans^=1;
				val[x]=0;
			} else val[x]=fx;
		} else
		{
			if (x==y) Ans^=1; 
			else addedge(x,y,fx,fy);
		}
	}
	ansf[0]=1,ansf[1]=0;
	memset(bo,0,sizeof(bo));
	for (int i=1; i<=n; i++) if (!bo[i])
	{
		bo[q[l=r=1]=i]=1;
		while (l<=r)
		{
			x=q[l++];
			for (int j=hd[x]; j; j=e[j].next)
				if (!bo[e[j].to]) bo[e[j].to]=1,q[++r]=e[j].to;
		}
		x=q[r];
		if (val[x]==1) f[x][0][0][0]=f[x][1][1][1]=1; else
		if (val[x]==-1) f[x][0][0][1]=f[x][1][1][0]=1; else
		f[x][0][0][0]=f[x][1][1][0]=1;
		if (hd[x]) x=dfs(e[hd[x]].to,x,x);
		nwf[0]=nwf[1]=0;
		for (int j=0; j<2; j++)
			for (int k=0; k<2; k++)
				add(nwf[0],f[x][j][k][0]),add(nwf[1],f[x][j][k][1]);
		Ansf[0]=(1ll*ansf[0]*nwf[0]+1ll*ansf[1]*nwf[1])%mod;
		Ansf[1]=(1ll*ansf[1]*nwf[0]+1ll*ansf[0]*nwf[1])%mod;
		ansf[0]=Ansf[0],ansf[1]=Ansf[1];
	}
	printf("%d\n",ansf[Ans]);
	return 0;
}