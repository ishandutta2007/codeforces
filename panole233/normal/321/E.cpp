#include<bits/stdc++.h>
using namespace std;

int s[4001][4001],f[4001][801],sta[801][4001],tp[801],po[801][4001],n,k,l,r,mid,ans,x,y;

int read()
{
	int p=0; char c=getchar();
	while (c>'9'||c<'0') c=getchar();
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p;
}

int main()
{
	n=read(),k=read();
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) s[j][i]=read();
	for (int i=1; i<=n; i++) s[i][i]=0;
	for (int i=1; i<n; i++)
		for (int j=i+1; j<=n; j++) s[i][j]+=s[i][j-1];
	for (int j=2; j<=n; j++)
		for (int i=j-1; i; i--) s[i][j]+=s[i+1][j];
	sta[1][tp[1]=1]=0,f[0][0]=0,po[1][1]=1;
	for (int i=1; i<=n; i++)
		for (int j=min(k,i); j; j--)
		{
			l=1,r=tp[j];
			while (l<=r)
			{
				mid=(l+r)>>1;
				if (po[j][mid]<=i) ans=mid,l=mid+1; else r=mid-1;
			}
			f[i][j]=f[sta[j][ans]][j-1]+s[sta[j][ans]+1][i];
			if (i<n&&j!=k)
			{
				while (tp[j+1])
				{
					x=sta[j+1][tp[j+1]],y=po[j+1][tp[j+1]];
					if (y>i&&f[x][j]+s[x+1][y]>f[i][j]+s[i+1][y]) {tp[j+1]--; continue;}
					l=i+1,r=n,ans=-1;
					while (l<=r)
					{
						mid=(l+r)>>1;
						if (f[x][j]+s[x+1][mid]>f[i][j]+s[i+1][mid]) ans=mid,r=mid-1;
						else l=mid+1;
					}
					if (ans!=-1) sta[j+1][++tp[j+1]]=i,po[j+1][tp[j+1]]=ans;
					break;
				}
				if (!tp[j+1]) sta[j+1][++tp[j+1]]=i,po[j+1][tp[j+1]]=i+1;
			}
		}
	printf("%d\n",f[n][k]);
	return 0;
}