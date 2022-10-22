// Author: Little09
// Problem: C. Substring Game in the Lesson
// Contest: Codeforces Round #586 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1220/problem/C
// Memory Limit: 0.25 MB
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
char a[N];


void work()
{
	//cin >> n;
	//for (int i=1;i<=n;i++) cin >> a[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (a+1);
	n=strlen(a+1);
	char mn='z'+1;
	for (int i=1;i<=n;i++) 
	{
		mn=min(mn,a[i]);
		if (mn<a[i]) cout << "Ann\n";
		else cout << "Mike\n";
	}
	return 0;
}