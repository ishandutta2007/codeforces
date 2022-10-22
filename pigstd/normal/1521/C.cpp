#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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

const int M=1e4+10;
int p[M];

void solve()
{
	int n=read(),X=0,Y=0,x=0;
	for (int i=1;i<=n/2;i++)
	{
		cout<<"? 2"<<' '<<i*2-1<<' '<<i*2<<' '<<1<<endl;
		int ans;cin>>ans;
		if (ans==1)x=i*2-1;
		else if (ans==2)
		{
			if (!X)X=i*2;
			else Y=i*2;
		}
	}
	if (n&1)
	{
		cout<<"? 2 1 "<<n<<" 1"<<endl;
		int ans;cin>>ans;
		if (ans==2)
		{
			if (!X)X=n;
			else if (!Y)Y=n;
		}
	}
	if (!x)
	{
		if (!Y)x=X;
		else
		{
			cout<<"? 2 "<<X<<' '<<Y<<" 1"<<endl;
			int ans;cin>>ans;
			if (ans==1)x=X;
			else x=Y;
		}
	}p[x]=1;
	for (int i=1;i<=n;i++)
	{
		if (i==x)continue;
		cout<<"? 1 "<<x<<' '<<i<<' '<<n-1<<endl;
		cin>>p[i];
	}cout<<"!";
	for (int i=1;i<=n;i++)cout<<' '<<p[i];cout<<endl;
}

signed main()
{
	WT{solve();}
	return 0;
}