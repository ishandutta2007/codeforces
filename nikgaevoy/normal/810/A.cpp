#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <cstdio>
#include <ctime>
#include <cassert>

#include <conio.h>

using namespace std;

int main ()
{
    int n, k;

    cin >> n >> k;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int t;

        cin >> t;

        sum += t;
    }

    int dif = n * k - sum;

    cout << max (2 * dif - n, 0) << endl;

    return 0;
}