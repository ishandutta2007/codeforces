#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,a[M],q,sum[2][M];
char s[M];

signed main()
{
	n=read(),q=read();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)a[i]=s[i]-'0';
	for (int i=2;i<=n;i++)
	{
		sum[0][i]=sum[0][i-1],sum[1][i]=sum[1][i-1];
		if (a[i]==a[i-1])sum[a[i]][i]++;
	}
	while(q--)
	{
		int l=read()+1,r=read();
		int c0=sum[0][r]-sum[0][l-1],c1=sum[1][r]-sum[1][l-1];
		cout<<c0+c1-min(c0,c1)+1<<'\n';
	}
	return 0;
}