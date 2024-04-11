#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>

#define rep(i,n)	for(int i = 0;i < (n);i++)
#define rep2(i,n)	for(int i = 1;i <= (n);i++)
#define each(i,x)	for(auto & i : x)

using namespace std;

int main()
{
	int n;
	cin >> n;
	rep(i,n)
	{
		rep(j,n/2-1)cout<< (n*n-(i*n/2+j)) <<' ' <<(i*n/2+j+1) << ' ';
		cout << (n*n-(i*n/2+n/2-1)) << ' ' << (i*n/2+n/2) << endl;
	}
	return 0;
}