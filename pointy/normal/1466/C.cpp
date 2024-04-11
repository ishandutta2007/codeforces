// Author: Little09
// Problem: C. Canine poetry
// Contest: Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/C
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
char a[N];
int b[N];

void work()
{
	cin >> (a+1);
	n=strlen(a+1);
	for (int i=1;i<=n;i++) b[i]=a[i]-'a';
	int ans=0;
	for (int i=2;i<=n;i++)
	{
		int l=max(i-2,1),fl=0;
		for (int j=l;j<i;j++)
		{
			if (b[i]==b[j]) fl=1;
		}
		if (fl==1) ans++,b[i]=-1;
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