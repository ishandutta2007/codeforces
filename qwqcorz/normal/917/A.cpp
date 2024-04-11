#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool can[N][N];
char a[N];
void GreenDay()
{
	scanf("%s",a+1);
	int n=strlen(a+1),ans=0;
	for (int i=1;i<=n;i++)
	for (int j=i,sum=0,tot1=0,tot2=0;j<=n;j++)
	{
		if ((sum+=a[j]=='('||a[j]=='?'?1:-1)<0) break;
		tot1+=a[j]=='(',tot2+=a[j]==')';
		if ((j-i+1)%2==0&&max(tot1,tot2)<=(j-i+1)/2) can[i][j]=1;
	}
	for (int i=n;i>=1;i--)
	for (int j=i,sum=0,tot1=0,tot2=0;j>=1;j--)
	{
		if ((sum+=a[j]==')'||a[j]=='?'?1:-1)<0) break;
		tot1+=a[j]=='(',tot2+=a[j]==')';
		if ((i-j+1)%2==0&&max(tot1,tot2)<=(i-j+1)/2) ans+=can[j][i];
	}
	print(ans);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}