// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
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
#include <iomanip>
/***********MACROS***************/

#define ll  int64_t 
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
 
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
int n;
int e[27][27];
string s[101];
bool visited[27];
/*********FUNCTIONS**************/
int getID(char c)
{
	if(c == ' ') return 0;
	return c - 'a' + 1;
}
 
int MAIN()
{
	memset(e, 0, sizeof(e));
	for(int i = 1; i <= 26; i++)
		e[0][i] = true;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] += " ";
	}
	for(int i = 1; i < n; i++)
	{
		int pos = 0;
		while(s[i][pos] == s[i+1][pos]) pos ++;
		e[getID(s[i][pos])][getID(s[i+1][pos])] = true;
	}
	for(int k = 0; k <= 26; k++)
		for(int i = 0; i <= 26; i++)
			for(int j = 0; j <= 26; j++)
				e[i][j] |= e[i][k] & e[k][j];
	bool haveCycle = false;
	for(int i = 0; i <= 26; i++)
		haveCycle |= e[i][i];
	if(haveCycle)
		cout << "Impossible" << endl;
	else
	{
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i <= 26; i++)
		{
			int now = 0;
			for(int j = 0; j <= 26; j++)
			{
				bool valid = (!visited[j]);
				for(int k = 0; k <= 26; k++)
					if(visited[k] == false && e[k][j])
						valid = false;
				if(valid)
				{
					now = j;
					break;
				}
			}
			if(i > 0)
				cout << char('a' + now - 1);
			visited[now] = true;
		}
		cout << endl;
	}
	return 0;
}
/***********MAIN**************/
 
signed main(){

	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
 
//