#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=110;
int ans1,ans2,n,a[M],b[M],cnt;

bool cmp(int a,int b){return a>b;}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int k=read();
		for (int j=1;j<=k;j++)
			b[j]=read();
		for (int j=1;j<=k/2;j++)ans1+=b[j];
		for (int j=k-k/2+1;j<=k;j++)ans2+=b[j];
		if (k&1)a[++cnt]=b[(k+1)/2];
	}sort(a+1,a+1+cnt,cmp);
	for (int i=1;i<=cnt;i+=2)ans1+=a[i],ans2+=a[i+1];
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}