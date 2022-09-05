#include<bits/stdc++.h>
using namespace std;

const int m1=998244853,m2=1012200221,mod=1000000007;
int f[2][2010][2010][2],n,m,ans;
char s[2][2010],t[2010];

struct node
{
	int a,b;
	node operator +(char A) {return (node){(27ll*a+A-'a'+1)%m1,(27ll*b+A-'a'+1)%m2};}
	bool operator ==(node B) {return a==B.a&&b==B.b;}
}sh[2][2010][2010],th[2010][2010];

void add(int &x,int y) {x=(x+y>=mod?x+y-mod:x+y);}

int main()
{
	scanf("%s%s%s",s[0]+1,s[1]+1,t+1),n=strlen(s[0]+1),m=strlen(t+1),ans=0;
	if (m==1)
	{
		for (int ovo=0; ovo<2; ovo++)
			for (int i=1; i<=n; i++) ans+=(s[ovo][i]==t[1]);
		return printf("%d\n",ans),0;
	}
	for (int ovo=0; ovo<2; ovo++)
		for (int i=1; i<=n; i++)
		{
			sh[ovo][i][i]=(node){s[ovo][i]-'a'+1,s[ovo][i]-'a'+1};
			for (int j=i+1; j<=n; j++) sh[ovo][i][j]=(sh[ovo][i][j-1]+s[ovo][j]);
			for (int j=i-1; j>=1; j--) sh[ovo][i][j]=(sh[ovo][i][j+1]+s[ovo][j]);
		}
	for (int panole=0; panole<2; panole++)
	{
		memset(f,0,sizeof(f));
		for (int i=1; i<=m; i++)
		{
			th[i][i]=(node){t[i]-'a'+1,t[i]-'a'+1};
			for (int j=i+1; j<=m; j++) th[i][j]=(th[i][j-1]+t[j]);
			for (int j=i-1; j>=1; j--) th[i][j]=(th[i][j+1]+t[j]);
		}
		for (int i=1; i<=n; i++)
			for (int j=i; j&&2*(i-j+1)<=m; j--)
			{
				if (sh[0][i][j]==th[1][i-j+1]&&sh[1][j][i]==th[i-j+2][2*(i-j+1)]) f[1][i][2*(i-j+1)][1]++;
				if (sh[1][i][j]==th[1][i-j+1]&&sh[0][j][i]==th[i-j+2][2*(i-j+1)]) f[0][i][2*(i-j+1)][1]++;
			}
		for (int i=1; i<=n; i++)
		{
			if (s[0][i]==t[1]) f[0][i][1][1]++;
			if (s[1][i]==t[1]) f[1][i][1][1]++;
		}
		for (int j=1; j<m; j++)
			for (int ovo=0; ovo<2; ovo++)
				for (int i=1; i<=n; i++)
					for (int k=0; k<2; k++)
					{
						if (k==0&&s[ovo^1][i]==t[j+1]) add(f[ovo^1][i][j+1][1],f[ovo][i][j][0]);
						if (i<n&&s[ovo][i+1]==t[j+1]) add(f[ovo][i+1][j+1][0],f[ovo][i][j][k]);
					}
		for (int ovo=0; ovo<2; ovo++)
			for (int i=1; i<=n; i++)
				for (int k=0; k<2; k++) add(ans,f[ovo][i][m][k]);
		for (int i=1; i<n; i++)
			for (int j=i+1; j<=n&&(j-i+1)*2<=m; j++)
			{
				if (sh[0][i][j]==th[m][m-(j-i)]&&sh[1][j][i]==th[m-(j-i)-1][m-2*(j-i)-1]) add(ans,f[1][i][m-2*(j-i)-1][(j-i+1)*2==m]);
				if (sh[1][i][j]==th[m][m-(j-i)]&&sh[0][j][i]==th[m-(j-i)-1][m-2*(j-i)-1]) add(ans,f[0][i][m-2*(j-i)-1][(j-i+1)*2==m]);
			}
		for (int i=1; i<=m-i+1; i++) swap(t[i],t[m-i+1]);
	}
	if (!(m&1))
	{
		for (int i=(m>>1); i<=n; i++)
		{
			int j=i-(m>>1)+1;
			if (sh[0][i][j]==th[1][i-j+1]&&sh[1][j][i]==th[i-j+2][2*(i-j+1)]) ans--;
			if (sh[1][i][j]==th[1][i-j+1]&&sh[0][j][i]==th[i-j+2][2*(i-j+1)]) ans--;
		}
		if (m!=2)
		{
			for (int i=1; i<=n-(m>>1)+1; i++)
			{
				int j=i+(m>>1)-1;
				if (sh[0][i][j]==th[m][m-(j-i)]&&sh[1][j][i]==th[m-(j-i)-1][m-2*(j-i)-1]) ans--;
				if (sh[1][i][j]==th[m][m-(j-i)]&&sh[0][j][i]==th[m-(j-i)-1][m-2*(j-i)-1]) ans--;
			}
		}
		ans=(ans+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}