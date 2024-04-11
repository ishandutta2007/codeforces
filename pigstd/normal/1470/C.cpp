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

int n,k,x;

int f(int x)
{
	x%=n;
	if (x<=0)return x+n;
	else return x;
}

signed main()
{
	n=read(),k=read();
	int now=1,p;
	for (p=1;;p++)
	{
		cout<<"? "<<now<<endl;cin>>x;
		if (x!=k)break;
		now+=p+1;if (now>n)now-=n;
	}
	if (x>k)
		for (int i=now-1;i>=now-p;i--)
		{
			cout<<"? "<<f(i)<<endl;cin>>x;
			if (x==k)
			{
				cout<<"! "<<f(i)<<endl;
				return 0;
			}
		}
	else
		for (int i=now+1;i<=now+p;i++)
		{
			cout<<"? "<<f(i)<<endl;cin>>x;
			if (x==k)
			{
				cout<<"! "<<f(i)<<endl;
				return 0;
			}
		}
	return 0;
}