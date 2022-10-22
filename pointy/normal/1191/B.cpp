// Author: Little09
// Problem: B. Tokitsukaze and Mahjong
// Contest: Codeforces - Codeforces Round #573 (Div. 2)
// URL: https://codeforces.com/contest/1191/problem/B
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
int x,y,z;
map<char,int>q;
bool check(int x,int y)
{
	if (x%10!=y%10) return 0;
	x/=10,y/=10;
	if (abs(x-y)==1||abs(x-y)==2) return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	char a,b,c;
	cin>>x>>a>>y>>b>>z>>c;
	q['s']=1,q['m']=2,q['p']=3;
	int X=x*10+q[a];
	int Y=y*10+q[b];
	int Z=z*10+q[c];
	if (X>Y) swap(X,Y);
	if (Y>Z) swap(Y,Z);
	if (X>Z) swap(X,Z);
	if (X>Y) swap(X,Y);
	if (Y>Z) swap(Y,Z);
	if (X>Z) swap(X,Z);
	if (X>Y) swap(X,Y);
	if (Y>Z) swap(Y,Z);
	if (X>Z) swap(X,Z);
	if (X==Y&&Y==Z)
	{
		cout << 0 << endl;
		return 0;
	}
	if (a==b&&b==c&&X/10+1==Y/10&&Y/10+1==Z/10)
	{
		cout << 0 << endl;
		return 0;
	}
	if (X==Y||Y==Z||Z==X)
	{
		cout << 1 << endl;
		return 0;
	}
	if (check(X,Y)||check(Y,Z)||check(X,Z))
	{
		cout << 1 << endl;
		return 0;
	}
	cout << 2 << endl;
	return 0;
}