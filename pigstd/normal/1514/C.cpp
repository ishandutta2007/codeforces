#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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

const int Mod=1e9+7;
const int M=1e5+10;
int t[M],cnt,n;

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%n;
		a=a*a%n,b>>=1;
	}return res;
}

signed main()
{
	n=read();t[1]=1;int res=1;
	for (int i=2;i<=n;i++)
		if (__gcd(n,i)==1)t[i]=1,res=res*i%n;
	if (res!=1)
		t[poww(res,Mod-2)]=0;
	for (int i=1;i<=n;i++)
		if (t[i])cnt++;
	cout<<cnt<<endl;
	for (int i=1;i<=n;i++)
		if (t[i])cout<<i<<' ';
	return 0;
}
/*

*/