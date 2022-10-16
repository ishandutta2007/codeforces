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
#include <sstream>
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	string str;

	cin >> str;

	if (str.find ("CC") != str.npos ||
		str.find ("YY") != str.npos ||
		str.find ("MM") != str.npos)
	{
		cout << "No" << endl;

		return;
	}

    if (str.front () == '?' || str.back () == '?' ||
        str.find ("??") != str.npos ||
        str.find ("C?C") != str.npos ||
        str.find ("Y?Y") != str.npos ||
        str.find ("M?M") != str.npos)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}