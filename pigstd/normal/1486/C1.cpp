#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e4+10;
int T,a[M],n;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	cin>>n;int k,k1,k2;
	cout<<"? "<<1<<' '<<n<<endl;
	cin>>k;bool f=0;
	if (n==2)
	{
		if (k==1)cout<<"! "<<2<<endl;
		else cout<<"! 1"<<endl;
		return 0;
	}
	if (k!=n&&k!=1)
	{
		cout<<"? "<<k<<' '<<n<<endl;
		cin>>k1;if (k1==k)f=1;
		else f=0;
	}
	else if (k==n)f=0;
	else f=1;
	if (f==1)
	{
		int tl=k+1,tr=n,p;
		if (tl==tr){cout<<"!"<<' '<<tl<<endl;return 0;}
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			cout<<"? "<<k<<' '<<Mid<<endl;
			cin>>k2;
			if (k2==k)tr=Mid-1,p=Mid;
			else tl=Mid+1;
		}
		cout<<"! "<<p<<endl;
	}
	else
	{
		int tl=1,tr=k-1,p=1;
		if (tl==tr){cout<<"! "<<tl<<endl;return 0;}
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			cout<<"? "<<Mid<<' '<<k<<endl;
			cin>>k2;
			if (k2==k)tl=Mid+1,p=Mid;
			else tr=Mid-1;
		}
		cout<<"! "<<p<<endl;
	}
	return 0;
}