#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>
#include <string>

#include <cassert>
#include <cmath>

using namespace std;

template<class T>
T up (T x)
{
	T r = 1;

	while (r <= x)
		r <<= 1;

	return r;
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
	long long n, k;

	cin >> n >> k;

	if (k == 1)
		cout << n << endl;
	else if (2 <= k)
		cout << up (n) - 1 << endl;
    else
    	assert (false);
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    solve ();

    return 0;
}