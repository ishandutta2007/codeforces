#include<bits/stdc++.h>
using namespace std;

bool bo[110][110];
int m,n,fa[11010],ans,mod,px[210],py[210],pn,po[11010],np,mat[210][210];
char s[110];

int ask(int x) {return fa[x]==x?x:fa[x]=ask(fa[x]);}
int calc(int x,int y) {return x*(m+1)+y+1;}

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

int solve()
{
	if (!(--np)) return 1; 
	for (int i=1; i<=np; i++)
		for (int j=1; j<=np; j++) 
		{
			mat[i][j]%=mod;
			if (mat[i][j]<0) mat[i][j]+=mod;
		}
	int ans=1;
	for (int i=1,po; i<=np; i++)
	{
		po=-1;
		for (int j=i; j<=np; j++)
			if (mat[j][i]) {po=j; break;}
		if (po==-1) return 0;
		if (po!=i) 
		{
			for (int j=1; j<=np; j++) swap(mat[i][j],mat[po][j]);
			ans=(ans==0?0:mod-ans);
		}
		int inv=quickmi(mat[i][i],mod-2);
		ans=1ll*ans*mat[i][i]%mod;
		for (int j=1; j<=np; j++) mat[i][j]=1ll*mat[i][j]*inv%mod;
		for (int j=i+1,nw; j<=np; j++) if (nw=mat[j][i])
			for (int k=1; k<=np; k++) mat[j][k]=(mat[j][k]+1ll*(mod-nw)*mat[i][k])%mod;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d",&n,&m,&mod);
	for (int i=1; i<=(n+1)*(m+1); i++) fa[i]=i;
	for (int i=1; i<=n; i++)
	{
		scanf("%s",s);
		for (int j=0; j<m; j++)
			if (s[j]=='/') 
			{
				if (ask(calc(i-1,j+1))==ask(calc(i,j))) return puts("0"),0;
				fa[ask(calc(i-1,j+1))]=ask(calc(i,j));
			} else
			if (s[j]=='\\')
			{
				if (ask(calc(i,j+1))==ask(calc(i-1,j))) return puts("0"),0;
				fa[ask(calc(i,j+1))]=ask(calc(i-1,j));
			} else
			px[++pn]=i,py[pn]=j+1;
	}
	np=0;
	for (int i=0; i<=n; i++)
		for (int j=(i&1); j<=m; j+=2)
		{
			bo[i][j]=1;
			if (fa[calc(i,j)]==calc(i,j)) po[calc(i,j)]=(++np);
		}
	if (np<=pn+1)
	{
		memset(mat,0,sizeof(mat));
		for (int i=1,x,y; i<=pn; i++) 
			if (bo[px[i]-1][py[i]-1])
			{
				if ((x=ask(calc(px[i]-1,py[i]-1)))!=(y=ask(calc(px[i],py[i]))))
					mat[po[x]][po[y]]--,mat[po[y]][po[x]]--,mat[po[x]][po[x]]++,mat[po[y]][po[y]]++;
			} else
			{
				if ((x=ask(calc(px[i],py[i]-1)))!=(y=ask(calc(px[i]-1,py[i]))))
					mat[po[x]][po[y]]--,mat[po[y]][po[x]]--,mat[po[x]][po[x]]++,mat[po[y]][po[y]]++;
			}
		ans+=solve();
	}
	np=0;
	for (int i=0; i<=n; i++)
		for (int j=((i&1)^1); j<=m; j+=2)
			if (fa[calc(i,j)]==calc(i,j)) po[calc(i,j)]=(++np);
	if (np<=pn+1)
	{
		memset(mat,0,sizeof(mat));
		for (int i=1,x,y; i<=pn; i++) 
			if (!bo[px[i]-1][py[i]-1])
			{
				if ((x=ask(calc(px[i]-1,py[i]-1)))!=(y=ask(calc(px[i],py[i]))))
					mat[po[x]][po[y]]--,mat[po[y]][po[x]]--,mat[po[x]][po[x]]++,mat[po[y]][po[y]]++;
			} else
			{
				if ((x=ask(calc(px[i],py[i]-1)))!=(y=ask(calc(px[i]-1,py[i]))))
					mat[po[x]][po[y]]--,mat[po[y]][po[x]]--,mat[po[x]][po[x]]++,mat[po[y]][po[y]]++;
			}
		ans+=solve();
	}
	printf("%d\n",ans%mod);
	return 0;
}