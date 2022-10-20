#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N][N];

signed main()
{
	int n=read(),m=read();
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++) a[i][j]=read();
	for (int i=0;i<m;i++)
	for (int j=i;j<m;j++)
	{
		for (int k=0;k<n;k++) swap(a[k][i],a[k][j]);
		bool flag=1;
		for (int k=0;k<n;k++)
		{
			int tot=0;
			for (int t=0;t<m;t++) if (a[k][t]!=t+1) tot++;
			if (tot>2){flag=0;break;}
		}
		if (flag) return puts("YES"),0;
		for (int k=0;k<n;k++) swap(a[k][i],a[k][j]);
	}
	puts("NO");
	
	return 0;
}