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
int n,c[M],x[M],f=-1;
double res;
struct node
{
	int id,val;
}a[M];
int cmp(node a,node b){return a.val>b.val;}
vector<int>ans;

signed main()
{
	n=read();int N=2e5;
	for (int i=1;i<=n;i++)
		c[i]=read(),x[i]=read();
	for (int i=1;i<=20;i++)
	{
		int sum=0;
		for (int j=1;j<=N;j++)a[j].val=0,a[j].id=j;
		for (int j=1;j<=n;j++)
			if (i<=x[j])a[c[j]].val+=i;
			else a[c[j]].val+=x[j];
		sort(a+1,a+N+1,cmp);
		for (int j=1;j<=i;j++)sum+=a[j].val;
		if (sum*1.0/i>res)
		{
			res=sum*1.0/i;ans.clear();
			for (int j=1;j<=i;j++)ans.pb(a[j].id);
		}
//		cout<<sum<<endl;
	}
	for (int j=1;j<=N;j++)a[j].val=0,a[j].id=j;int sum=0;
	for (int j=1;j<=n;j++)a[c[j]].val+=x[j];
	sort(a+1,a+N+1,cmp);
	for (int i=1;i<=20;i++)sum+=a[i].val;
	for (int i=21;i<=N;i++)
	{
		sum+=a[i].val;
		if (sum*1.0/i>res)res=sum*1.0/i,f=i;
	}
	if (f!=-1)
		for (int i=1;i<=f;i++)ans.pb(a[i].id);
	cout<<ans.size()<<endl;
	for (auto x:ans)cout<<x<<' ';
	return 0;
}