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
int n,a[M];

int isprime(int x)
{
	for (int i=2;i*i<=x;i++)
		if (x%i==0)return 0;
	return 1;
}

signed main()
{
//	cout<<isprime(11)<<endl;
	WT
	{
		n=read();int sum=0;
		for (int i=1;i<=n;i++)
			a[i]=read(),sum+=a[i];
		if (!isprime(sum))
		{
			cout<<n<<endl;
			for (int i=1;i<=n;i++)cout<<i<<' ';
			puts("");
		}
		else
		{
			for (int i=1;i<=n;i++)
				if (a[i]&1)
				{
					cout<<n-1<<endl;
					for (int j=1;j<=n;j++)
						if (i!=j)cout<<j<<' ';
					puts("");break;
				}
		}
	}
	return 0;
}