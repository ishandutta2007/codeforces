// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <iomanip>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
/***********MACROS***************/
//#define int long long 
#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
#define mod 1000000007
#define inf 100000000
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/

/*********FUNCTIONS**************/
int get(int a, int b) {
	if (b == 0) return 0;
	int ret = 0;
	while (b % a == 0) {
		ret += 1;
		b /= a;
	}
	return ret;
}
/***********MAIN**************/

signed main(){ 
 	int n;
	cin >> n;
	int m[n + 1][n + 1];
	int two[n + 1][n + 1];
	int five[n + 1][n + 1];
	char five1[n + 1][n + 1];
	char two1[n + 1][n + 1];
	memset(two, 0, sizeof(two));
	memset(five, 0, sizeof(five));
	int a = -1;
	int b = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &m[i][j]);
			int x = m[i][j];
			if (x == 0)
			{
				a = i + 1;
				b = j + 1;
				continue;
			}
			two[i][j] = get(2, x);
			five[i][j] = get(5, x);
 
		}
	}
	for (int i = 1; i < n; i++)
	{
		two[i][0] += two[i - 1][0];
		five[i][0] += five[i - 1][0];
		two[0][i] += two[0][i - 1];
		five[0][i] += five[0][i - 1];
		two1[i][0] = 'D';
		two1[0][i] = 'R';
		five1[i][0] = 'D';
		five1[0][i] = 'R';
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (two[i - 1][j] < two[i][j - 1])
			{
				two[i][j] += two[i - 1][j];
				two1[i][j] = 'D';
			}
			else
			{
				two[i][j] += two[i][j - 1];
				two1[i][j] = 'R';
			}
			if (five[i - 1][j] < five[i][j - 1])
			{
				five[i][j] += five[i - 1][j];
				five1[i][j] = 'D';
			}
			else
			{
				five[i][j] += five[i][j - 1];
				five1[i][j] = 'R';
			}
		}
	}
	int ans = min(five[n - 1][n - 1], two[n - 1][n - 1]);
	if (a != -1 && b != -1 && ans > 1)
	{
 
		cout << 1 << endl;
		for (int i = 1; i < a; i++)cout << 'D';
		for (int j = 1; j < b; j++)cout << 'R';
		for (int i = a; i < n; i++)cout << 'D';
		for (int j = b; j < n; j++)cout << 'R';
	}
	else if (five[n - 1][n - 1] < two[n - 1][n - 1])
	{
		cout << ans << endl;
		string x = "";
		int i = n - 1;
		int j = n - 1;
		while (i != 0 || j != 0)
		{
			x += five1[i][j];
			if (five1[i][j] == 'R')j--;
			else i--;
		}
		reverse(x.begin(), x.end());
		cout << x;
	}
	else
	{
		cout << ans << endl;
		string x = "";
		int i = n - 1;
		int j = n - 1;
		while (i != 0 || j != 0)
		{
			x += two1[i][j];
			if (two1[i][j] == 'R')j--;
			else i--;
		}
		reverse(x.begin(), x.end());
		cout << x;
	}
}