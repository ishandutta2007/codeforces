#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int n,a[M],d[M],q,sum;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int put(int x){cout<<(x%2==0?x/2:(x+1)/2)<<endl;}

signed main()
{
	n=read();for (int i=1;i<=n;i++)a[i]=read(),d[i]=a[i]-a[i-1];
	for (int i=2;i<=n;i++)
		sum+=d[i]>0?d[i]:0;
	put(sum+d[1]);
	q=read();
	while(q--)
	{
		int l=read(),r=read(),x=read();
		if (l!=1) sum+=max(0ll,d[l]+x)-max(0ll,d[l]);
		if (r!=n) sum+=max(0ll,d[r+1]-x)-max(0ll,d[r+1]);
		d[l]+=x,d[r+1]-=x;
//		cout<<sum+d[1]<<endl;
		put(sum+d[1]);
	}
	return 0;
}