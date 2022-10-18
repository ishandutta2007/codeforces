#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;

vector< vector<char> > c;

int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0 && (n / i) >= i)
            a = i, b = n / i;
    }
    cout << a << " " << b;
    return 0;
}