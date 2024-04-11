// Author: Little09
// Problem: D. Phoenix and Socks
// Contest: Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,l,r; 
int a[N],b[N],c[N],cntb,cntc;
map<int,int>q;
int calc(int *d,int cnt)
{
	int res=0;
	for (int i=2;i<=cnt;i++)
	{
		if (d[i]==d[i-1])
		{
			res++,i++;
		}
	}
	return res;
}

void work()
{
	cin >> n >> l >> r;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+l+1);
	sort(a+l+1,a+n+1);
	int tot=l+1;
	cntb=0,cntc=0;
	for (int i=1;i<=l;i++)
	{
		while (tot<=n&&a[tot]<a[i]) tot++;
		if (tot<=n&&a[tot]==a[i])
		{
			a[tot]=-1;
			++tot;
			continue;
		}
		b[++cntb]=a[i];
	}
	for (int i=l+1;i<=n;i++)
	{
		if (a[i]!=-1) c[++cntc]=a[i];
	}
	int p=(cntb+cntc)/2;
	int ans=p+abs(p-cntb);
	if (cntb>cntc) ans-=min(calc(b,cntb),abs(p-cntb));
	else ans-=min(calc(c,cntc),abs(p-cntb));
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}