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

const int M=55;
int n,a[M];

bool check(int x,int y,int z)
{
	if (x==2)x=-1;
	if (y==2)y=-1;
	if (z==2)z=-1;
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==1)cnt+=x;
		if (a[i]==2)cnt+=y;
		if (a[i]==3)cnt+=z;
		if (cnt<0)return 0;
	}return cnt==0;
}

signed main()
{
	WT
	{
		string s;cin>>s;n=s.size();
		for (int i=1;i<=n;i++)
			a[i]=s[i-1]-'A'+1;int f=0;
		for (int i=1;i<=2;i++)
			for (int j=1;j<=2;j++)
				for (int k=1;k<=2;k++)
					if (check(i,j,k))f=1;
		if (f)YES
		else NO
	}
	return 0;
}