#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int dis[2097152],A[10],fn,f[10001],la[2097152],n,a[100001],x,ans[100001][3],an,y,nw,Nw;
vector<int> v[21];

void solve(int N)
{
	A[0]=7; A[1]=21; A[2]=73; A[3]=273; A[4]=1057;
	A[5]=4161; A[6]=16513; A[7]=65793; A[8]=262657; A[9]=1049601;
	fn=0;
	for (int j=0; j<10; j++)
		for (int k=A[j]; k<N; k<<=1) f[++fn]=k;
	for (int i=0; i<=20; i++) v[i].clear();
	for (int i=1; i<N; i++) dis[i]=10000;
	la[0]=0; dis[0]=0; v[0].push_back(0);
	for (int i=0; i<20; i++)
	{
		for (int j=0; j<v[i].size(); j++)
		{
			if (dis[v[i][j]]<i) continue;
			x=v[i][j];
			for (int k=la[x]+1; k<=fn; k++)
				if (dis[f[k]^x]>i+1) dis[f[k]^x]=i+1,v[i+1].push_back(f[k]^x),la[f[k]^x]=k;
		}
	}
}

void work(int l,int r)
{
	if (Nw!=(1<<(r-l+1))) solve(1<<(r-l+1)),Nw=(1<<(r-l+1)); x=0;
	for (int i=l; i<=r; i++) x=(x<<1)+a[i];
	if (dis[x]==10000) {printf("NO\n"); exit(0);}
	while (x)
	{
		y=f[la[x]]; x^=y; an++; nw=0;
		for (int j=r-l; j>=0; j--)
			if ((y>>j)&1) ans[an][nw]=r-j,nw++;
	}
}

void print()
{
	if (an>n/3+12) {printf("NO\n"); return;}
	printf("YES\n%d\n",an);
	for (int i=1; i<=an; i++) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	Nw=0;
	if (n<21) {work(1,n),print(); return 0;}
	int i;
	for (i=1; i+21<=n;)
	{
		if (a[i]&&a[i+1]&&a[i+2]) ans[++an][0]=i,ans[an][1]=i+1,ans[an][2]=i+2,i+=3; else
		if (a[i]&&a[i+2]) ans[++an][0]=i,ans[an][1]=i+2,ans[an][2]=i+4,a[i+4]^=1,i+=3; else
		if (a[i+1]&&a[i+2]) ans[++an][0]=i+1,ans[an][1]=i+2,ans[an][2]=i+3,a[i+3]^=1,i+=3; else
		if (a[i]&&a[i+1])
		{
			if (a[i+3])
			{
				if (a[i+5])
				{
					ans[++an][0]=i+1,ans[an][1]=i+3,ans[an][2]=i+5;
					if (a[i+4]) ans[++an][0]=i,ans[an][1]=i+4,ans[an][2]=i+8,a[i+8]^=1;
					else ans[++an][0]=i,ans[an][1]=i+6,ans[an][2]=i+12,a[i+12]^=1,a[i+6]^=1;
					i+=6;
				} else
				{
					ans[++an][0]=i,ans[an][1]=i+3,ans[an][2]=i+6,a[i+6]^=1;
					if (a[i+4]) ans[++an][0]=i+1,ans[an][1]=i+4,ans[an][2]=i+7,a[i+7]^=1;
					else ans[++an][0]=i+1,ans[an][1]=i+6,ans[an][2]=i+11,a[i+6]^=1,a[i+11]^=1;
					i+=6;
				}
			} else
			{
				if (a[i+4]) ans[++an][0]=i,ans[an][1]=i+4,ans[an][2]=i+8,a[i+8]^=1;
				else ans[++an][0]=i,ans[an][1]=i+6,ans[an][2]=i+12,a[i+6]^=1,a[i+12]^=1;
				if (a[i+5]) ans[++an][0]=i+1,ans[an][1]=i+5,ans[an][2]=i+9,a[i+9]^=1;
				else ans[++an][0]=i+1,ans[an][1]=i+6,ans[an][2]=i+11,a[i+6]^=1,a[i+11]^=1;
				i+=6;
			}
		} else
		if (a[i]) ans[++an][0]=i,ans[an][1]=i+3,ans[an][2]=i+6,a[i+3]^=1,a[i+6]^=1,i+=3; else
		if (a[i+1]) ans[++an][0]=i+1,ans[an][1]=i+3,ans[an][2]=i+5,a[i+3]^=1,a[i+5]^=1,i+=3; else
		if (a[i+2]) ans[++an][0]=i+2,ans[an][1]=i+3,ans[an][2]=i+4,a[i+3]^=1,a[i+4]^=1,i+=3; else i+=3;
	}
	work(i,n),print();
	return 0;
}