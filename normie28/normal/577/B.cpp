// Thanks to robs77 for this template
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
#define inf 100000000000000000 
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
//#define mod 1000000007
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
ll arr[1000000 + 5];
bool mod[1000 + 5], tmp[1000 + 5];
/*********FUNCTIONS**************/
bool solve(int n, int m) {
	if (n > m)
		return true;
	for (int i = 0; i < n; ++i) {
		if (mod[0])
			return true;
		memset(tmp, 0, sizeof(tmp));
		for (int j = 0; j < m; ++j) {
			if (mod[j])
				tmp[j] = tmp[(j + arr[i]) % m] = true;
		}
		for (int j = 0; j < m; ++j)
			mod[j] = tmp[j];
		mod[arr[i] % m] = true;
	}
	return mod[0];
}
/***********MAIN**************/

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << (solve(n, m)? "YES": "NO") << '\n';
}