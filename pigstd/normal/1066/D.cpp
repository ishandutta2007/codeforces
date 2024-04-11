#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,m,k;
int a[M];

bool check(int x)
{
	int cnt=0,sum=0;
	for (int i=x+1;i<=n;i++)
	{
		if (sum+a[i]>k)cnt++,sum=a[i];
		else sum+=a[i];
	}
	if (sum!=0)cnt++;
	return cnt<=m;
}

signed main()
{
	n=read(),m=read(),k=read();
	for (int i=1;i<=n;i++)a[i]=read();
	int tl=0,tr=n,p=n;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (check(Mid))tr=Mid-1,p=Mid;
		else tl=Mid+1;
	}
	cout<<n-p<<endl;
	return 0;
}