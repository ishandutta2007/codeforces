#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[30],T,n,m,k,tmp,sum;
bool f[200001];
char s[200001];
long long ans;

long long getmin(long long a,long long b) {return a>b?b:a;}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&k); if (n<m) tmp=n,n=m,m=tmp;
		scanf("%s",s); memset(a,0,sizeof(a));
		for (int i=0; i<k; i++) a[s[i]-'A']++;
		f[0]=1; ans=1ll*n*m;
		for (int i=0; i<26; i++)
			if (a[i])
			{
				for (int j=1; j<=k; j++) f[j]=0;
				for (int j=0; j<26; j++)
					if (a[j]&&i!=j)
						for (int l=k-a[j]; l>=0; l--)
							if (f[l]) f[l+a[j]]=1;
				for (int j=(n-a[i]>0?n-a[i]:0); j<n; j++)
					if (f[j]) 
					{
						if (k-a[i]-j>=m) ans=0;
						else ans=getmin(ans,1ll*(n-j)*(m-(k-a[i]-j)));
					}
				for (int j=n; k-j>=m; j++)
					if (f[j]) {ans=0; break;}
			}
		printf("%I64d\n",ans);
	}
	return 0;
}