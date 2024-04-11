//AFO countdown:???
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

const int M=2e5+10;
int n,a[M],F;
vector<int>ans;

void work(int x)
{
	ans.pb(x);
	int tmp=a[x]^a[x+1]^a[x+2];
	a[x]=a[x+1]=a[x+2]=tmp;
}

bool check1()
{
	int p1=n+1,p2=0;
	for (int i=n;i>=1;i--)
		if (a[i]==0)break;
		else p1=i;
	for (int i=1;i<=n;i++)
		if (a[i]==0)break;
		else p2=i;
	if ((n-p1+1)%2==0)
	{
		F=1;
		for (int i=p1-1;i+2<=n;i+=2)
			work(i);
		return 1;
	}int p=0,cnt=0;
	for (int i=p1-1;i>=p2;i--)
		if (a[i]!=a[i+1])
		{
			if (cnt&1){p=i;break;}
			else cnt=1;
		}
		else cnt++;
	if (p==0)return 0;
	F=1;
	for (int i=p;i+2<=n;i+=2)
		work(i);
	return 1;
}

bool check2()
{
	int p1=0,p2=n+1;
	for (int i=1;i<=n;i++)
		if (a[i]==0)break;
		else p1=i;
	for (int i=n;i>=1;i--)
		if (a[i]==0)break;
		else p2=i;
	if (p1%2==0)
	{
		F=1;
		for (int i=p1-1;i>=1;i-=2)
			work(i);
		return 1;
	}int p=0,cnt=0;
	for (int i=p1+1;i<=p2;i++)
		if (a[i]!=a[i-1])
		{
			if (cnt&1){p=i;break;}
			else cnt=1;
		}
		else cnt++;
	if (p==0)return 0;
	F=1;
	for (int i=p-2;i>=1;i-=2)
		work(i);
	return 1;
}

signed main()
{
	WT
	{
		n=read();int cnt=0;F=0;ans.clear();
		for (int i=1;i<=n;i++)
			a[i]=read(),cnt+=a[i];
		if (cnt&1||cnt==n){NO continue;}
		if (!check1())check2();
		if (!F){NO continue;}
		if (a[1]==0)
		{
			for (int i=1;i<=n-2;i++)
				if (!a[i+1])continue;
				else if (a[i+2])work(i);
				else if (a[i+3])work(i+1);
				else work(i+1),work(i);
		}
		else
		{
			for (int i=n;i>=3;i--)
				if (!a[i-1])continue;
				else if (a[i-2])work(i-2);
				else if (a[i-3])work(i-3);
				else work(i-3),work(i-2);
		}YES
		cout<<ans.size()<<endl;
		for (int i=0;i<ans.size();i++)
			cout<<ans[i]<<' ';
		if (ans.size()!=0)puts("");
		for (int i=1;i<=n;i++)a[i]=0; 
	}
	return 0;
}
/*
1
4
1 0 1 0
*/