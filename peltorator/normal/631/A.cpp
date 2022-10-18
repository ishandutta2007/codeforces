#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <limits>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = 0, k = 0, a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        m |= a;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        k |= b;
    }
    cout << m + k;
	return 0;
}