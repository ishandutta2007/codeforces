#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    if (n <= 2)
        cout << n + 2;
    else
        cout << n - 2;
    return 0;
}