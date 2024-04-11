#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <queue>
#include <stack>
#include <fstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int a, b;

    cin >> a >> b;

    int cnt = 0;

    while (a <= b)
    {
        a *= 3;
        b <<= 1;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}