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

const int M=310;
int n,m,k,a[M],v[M];

signed main()
{
//	freopen("qwq.txt","w",stdout);
	n=read(),m=read(),k=read();//cout<<n<<' '<<m<<' '<<k<<endl;
	for (int i=1;i<=k;i++)a[i]=read(),v[a[i]]=1;//,cout<<a[i]<<' ';puts("");
	if (k==n||m>n*(n-1)/2-k+1)return puts("-1"),0;
	int p=0;
	for (int i=1;i<=n;i++)
		if (!v[i])p=i;
	for (int i=1;i<=n;i++)
		if (i!=p)cout<<i<<' '<<p<<endl;
	m-=n-1;
	for (int i=1;i<=n&&m;i++)
		for (int j=i+1;j<=n&&m;j++)
			if (!(i==p||j==p||(i==a[2]&&v[j])||(j==a[2]&&v[i])))
				cout<<i<<' '<<j<<endl,m--;
//	if (!m)cout<<m<<endl;
	return 0;
}