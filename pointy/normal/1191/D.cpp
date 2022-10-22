// Author: Little09
// Problem: D. Tokitsukaze, CSL and Stone Game
// Contest: Codeforces - Codeforces Round #573 (Div. 2)
// URL: https://codeforces.com/contest/1191/problem/D
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,tp; 
ll a[N];
void print(int x)
{
	x^=tp;
	if (x==1) cout << "cslnb" << endl;
	else cout << "sjfnb" << endl;
}

void work()
{
	//cin >> n;
	//for (int i=1;i<=n;i++) cin >> a[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int tmp=0;
	for (int i=1;i<n;i++) tmp+=(a[i]==a[i+1]);
	if (tmp>=2)
	{
		print(1);
		return 0;
	}
	else if (tmp==1)
	{
		for (int i=1;i<n;i++)
		{
			if (a[i]==a[i+1]) 
			{
				if (a[i]==0)
				{
					print(1);
					return 0;
				}
				a[i]--;
			}
		}
		// for (int i=1;i<=n;i++) cout << a[i] << " ";
		// cout << endl;
		for (int i=1;i<n;i++)
		{
			if (a[i]==a[i+1])
			{
				print(1);
				return 0;
			}
		}
		tp^=1;
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for (int i=1;i<=n;i++) ans+=a[i]-(i-1);
	print((ans&1)^1);
	return 0;
}