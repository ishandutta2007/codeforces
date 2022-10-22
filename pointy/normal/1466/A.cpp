// Author: Little09
// Problem: A. Bovine Dilemma
// Contest: Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/A
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

const int N=505;
int n,m; 
int a[N],b[N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	mem(b);
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			b[a[j]-a[i]]=1;
		}
	}
	int ans=0;
	for (int i=1;i<=100;i++) ans+=b[i];
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