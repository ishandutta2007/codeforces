// Author: Little09
// Problem: A. Tokitsukaze and Enhancement
// Contest: Codeforces - Codeforces Round #573 (Div. 2)
// URL: https://codeforces.com/contest/1191/problem/A
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
int n,m; 
int a[N];


void work()
{
	cin >> n;
	if (n%4==0) cout << "1 A" << endl;
	else if (n%4==1) cout << "0 A" << endl;
	else if (n%4==2) cout << "1 B" << endl;
	else cout << "2 A" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
	while (T--) work();
	return 0;
}