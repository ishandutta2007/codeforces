// Author: Little09
// Problem: CF1678A Tokitsukaze and All Zero Sequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1678A
// Memory Limit: 250 MB
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
int a[N],b[N];


void work()
{
	cin >> n;
	for (int i=1;i<=100;i++) b[i]=0;
	for (int i=1;i<=n;i++) cin >> a[i];
	int cnt=0,res=0,pp=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0) 
		{
			pp=1;
			continue;
		}
		if (b[a[i]]==0) b[a[i]]=1;
		else res++;
		cnt++;
	}
	if (res>0||pp) cout << cnt << endl;
	else cout << cnt+1 << endl;
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