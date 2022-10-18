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
    vector<int> a(n);
    for (int i = 0;  i< n; i++)
        cin >> a[i];
    if (n == 1)
    {
         if (a[0] == 15)
               cout << "DOWN";
               else if (a[0] == 0)
               cout << "UP";
               else
        cout << -1;
        return 0;
    }
    if (a[n - 1] == 15)
        cout << "DOWN";
    else if (a[n - 1] == 0)
        cout << "UP";
    else if (a[n - 2] < a[n - 1])
        cout << "UP";
    else
        cout << "DOWN";
	return 0;
}