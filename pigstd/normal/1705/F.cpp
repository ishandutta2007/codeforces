#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1010;
int a[M],n,b[M];

int query()
{
	for (int i=1;i<=n;i++)cout<<(a[i]?'T':'F');
	cout<<endl;
	int x;cin>>x;
	if (x==n)exit(0);
	return x;
}

signed main()
{
	n=read();
	int x1=query();
	for (int i=3;i<=n;i+=3)a[i]=1;
	int x2=query();
	memset(a,0,sizeof(a));
	for (int i=n/3*3+1;i<=n;i++)
	{
		a[i]=1;
		int x=query();
		if (x==x1-1)b[i]=0;
		else if (x==x1+1)b[i]=1;
		else assert(0);
		a[i]=0;
	}
	for (int i=1;i+2<=n;i+=3)
	{
		memset(a,0,sizeof(a));
		a[i]=a[i+1]=a[i+2]=1;
		int x=query();
		int cnt=(x-x1+3)/2;
		//T
		if (cnt==3){b[i]=b[i+1]=b[i+2]=1;continue;}
		if (cnt==0){b[i]=b[i+1]=b[i+2]=0;continue;}
		for (int i=3;i<=n;i+=3)a[i]=1;
		a[i]=a[i+2]=0,a[i+1]=1;
		x=query();
		if (x==x2+2)
		{
			b[i+1]=1,b[i+2]=0;
			if (cnt==2)b[i]=1;
			else b[i]=0;
		}
		else if (x==x2-2)
		{
			b[i+1]=0,b[i+2]=1;
			if (cnt==2)b[i]=1;
			else b[i]=0;
		}
		else if (cnt==2)b[i+1]=b[i+2]=1,b[i]=0;
		else b[i+1]=b[i+2]=0,b[i]=1;
	}
	memcpy(a,b,sizeof(a));
	query();
	assert(0);
	return 0;
}