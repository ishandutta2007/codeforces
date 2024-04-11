// Author: Little09
// Problem: G. Even-Odd XOR
// Contest: Codeforces Round #817 (Div. 4)
// URL: https://codeforces.com/contest/1722/problem/G
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
int n,m,res; 
int a[N];

int rd()
{
	int u=(rand()*100+rand())%(1000000000/n)+1;
	return res=res+u;
}

void work()
{
	cin >> n;
	res=0;
	while (1)
	{
		res=0;
		int ans=0;
		for (int i=1;i<n;i++) a[i]=rd();
		for (int i=1;i<n;i++) ans^=a[i];
		bool fl=0;
		for (int i=1;i<n;i++) if (ans==a[i]) fl=1;
		a[n]=ans;
		if (!fl)
		{
			for (int i=1;i<=n;i++) cout << a[i] << " ";
			cout << endl;
			return;
		}
	}
}

int main()
{
	srand(time(0));
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}