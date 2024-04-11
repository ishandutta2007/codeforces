// Author: Little09
// Problem: D. Replace by MEX
// Contest: Codeforces Global Round 9
// URL: https://codeforces.com/contest/1375/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[N],cnt,ans[N],mex;
int b[N];
bool used[N];
void updatemex()
{
	for (int i=0;i<=n;i++) b[i]=0;
	for (int i=1;i<=n;i++) b[a[i]]=1;
	for (int i=0;i<=n;i++) if (b[i]==0) {mex=i;break;}
}
void update(int x)
{
	ans[++cnt]=x;
	a[x]=mex;
	updatemex();
}

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) used[i]=0;
	updatemex();
	cnt=0;
	while (1)
	{
		int fl=0;
		for (int i=1;i<=n;i++) if (a[i]!=i-1) fl=1;
		if (fl==0) break;
		if (mex==n)
		{
			int fl=0;
			for (int i=1;i<=n;i++)
			{
				if (a[i]!=i-1) 
				{
					fl=1;
					update(i);
					break;
				}
			}
		}
		else
		{
			update(mex+1);
		}
		
		// for (int i=1;i<=n;i++) cout << a[i] << " ";
		// cout << endl;
	}
	cout << cnt << endl;
	for (int i=1;i<=cnt;i++) cout << ans[i] << " ";
	cout << endl;
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