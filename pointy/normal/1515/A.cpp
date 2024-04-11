// Author: Little09
// Problem: A. Phoenix and Gold
// Contest: Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/A
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
int n,m; 
int a[N],b[N];
void print()
{
	printYES;
	for (int i=1;i<=n;i++) cout << a[i] << " ";
	cout << endl;
}
bool check()
{
	for (int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for (int i=1;i<=n;i++)
	{
		if (b[i]==m) return 0;
	}
	return 1;
}

void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	if (check()) print();
	else 
	{
		int u=-1;
		for (int i=1;i<=n;i++) if (b[i]==m) swap(a[i],a[n]);
		if (check()) print();
		else printNO;
	}
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