#include <iostream>
//#include <set>
//#include <bitset>
//#include <stack>
//#include <algorithm>
//#include <string>
//#include <cmath>
//#include <vector>
//#include <limits>
//#include <list>
//#include <tuple>

using namespace std;
//#define pb push_back

#define fr(i,n) for(register int i = 0; i < n; i++)
//#define all(c) c.begin(),c.end()
//typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
//typedef long double real;
typedef ull number;/*
typedef vector<number> vi;
typedef vector<vi> vvi;
typedef set<number> si;
typedef vector<list<number>> graph;
typedef pair<number, number> point;*/

#define MODULO 1000000007
#define INV2 500000004
inline number sum3SolMod(number m)
{
	return ((((m + 2)% MODULO)*((m + 1) % MODULO) % MODULO)*INV2 % MODULO);
	//m+2 chosse m = m+2 chosse 2

}

inline number solveForM(number m)
{
	//x+2y+4z=m
	m >>= 1; //x+y+z=m

	if (m & 1)
	{
		return 2 * sum3SolMod(m / 2) % MODULO;
	}
	else
	{
		return (sum3SolMod(m / 2 - 1) + sum3SolMod(m / 2)) % MODULO;
	}

}


int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(0);*/
	number t, m;
	scanf("%lld", &t);
	//cin >> t;
	fr(i, t)
	{
		scanf("%lld", &m);
		//cin >> m;
		//cout << solveForM(m) << endl;
		printf("%lld\n", solveForM(m));
	}
	
	return 0;

}