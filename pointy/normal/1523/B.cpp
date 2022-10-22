// Author: Little09
// Problem: B. Lord of the Values
// Contest: Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/B
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
int a[N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	cout << 3*n << endl;
	for (int i=1;i<=n;i+=2)
	{
		cout << "2 " << i << " " << i+1 << endl;
		cout << "1 " << i << " " << i+1 << endl;
		cout << "2 " << i << " " << i+1 << endl;
		cout << "2 " << i << " " << i+1 << endl;
		cout << "1 " << i << " " << i+1 << endl;
		cout << "2 " << i << " " << i+1 << endl;
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