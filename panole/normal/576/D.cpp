#include<bits/stdc++.h>
using namespace std;

int n,m,c,w[151];
struct node{int x,y,lv;}e[400010];
bool cmp(node a,node b) {return a.lv<b.lv;}
pair<int,int> val[151];

struct mat
{
	unsigned long long a[151][3];
	mat operator *(mat A)
	{
		mat B;
		for (int i=1; i<=n; i++) B.a[i][0]=B.a[i][1]=B.a[i][2]=0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) if ((a[i][j>>6])>>(j&63)&1)
				B.a[i][0]|=A.a[j][0],B.a[i][1]|=A.a[j][1],B.a[i][2]|=A.a[j][2];
		return B;
	}
}f[31],T,TT;

int main()
{
	scanf("%d%d",&n,&m);
	if (n==1) return puts("0"),0;
	for (int i=1; i<=m; i++) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].lv),val[i]=make_pair(e[i].lv,i);
	sort(val+1,val+1+m),c=0;
	for (int i=1; i<=m; i++) 
	{
		if (i==1||val[i].first!=val[i-1].first) w[++c]=val[i].first;
		e[val[i].second].lv=c;
	}
	sort(e+1,e+1+m,cmp);
	w[c+1]=w[c]+200,f[0].a[n][n>>6]|=(1ull<<(n&63));
	for (int i=1; i<=n; i++) T.a[i][i>>6]=(1ull<<(i&63));
	if (w[1]!=0) return puts("Impossible"),0;
	int nw=1,ans=0;
	for (int mi,po,i=1; i<=c; i++)
	{
		mi=w[i+1]-w[i];
		for (po=0; (1<<po+1)<=mi; po++);
		while (nw<=m&&e[nw].lv==i) 
			f[0].a[e[nw].x][e[nw].y>>6]|=(1ull<<(e[nw].y&63)),nw++;
		for (int j=1; j<=po; j++) f[j]=(f[j-1]*f[j-1]);
		for (int j=po; j>=0; j--)
			if (ans+(1<<j)<=w[i+1])
			{
				TT=(T*f[j]);
				if (TT.a[1][n>>6]>>(n&63)&1) continue;
				ans+=(1<<j),T=TT;
			}
		if (ans!=w[i+1]) return printf("%d\n",ans+1),0;
	}
	return puts("Impossible"),0;
}