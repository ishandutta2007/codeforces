// Author: Little09
// Problem: CF1721D Maximum AND
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1721D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],b[N],c[N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> b[i];
	int ans=0;
	for (int i=30;i>=0;i--)
	{
		sort(a+1,a+n+1);
		sort(b+1,b+n+1,greater<int>());
		for (int j=1;j<=n;j++) c[j]=a[j]^b[j];
		for (int j=1;j<=n;j++) c[1]&=c[j];
		if (c[1]&(1<<i)) ans^=(1<<i);
		else 
		{
			for (int j=1;j<=n;j++) if (a[j]&(1<<i)) a[j]^=(1<<i);
			for (int j=1;j<=n;j++) if (b[j]&(1<<i)) b[j]^=(1<<i);
		}
	}
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