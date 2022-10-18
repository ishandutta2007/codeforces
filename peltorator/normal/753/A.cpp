#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;


int main()
{
    int n;
    cin >> n;
    int m = 0;
    while (m * (m + 1) / 2 <= n)
        m++;
    m--;
    cout << m << endl;
    for (int i = 1; i < m; i++)
        cout << i << " ";
    cout << n - m * (m - 1) / 2;
    return 0;
}