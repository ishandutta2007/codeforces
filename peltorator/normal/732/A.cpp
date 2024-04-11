#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, r;
    cin >> k >> r;
    int i = 1;
    while ((i * k) % 10 != 0 && (i * k) % 10 != r)
        i++;
    cout << i;
    return 0;
}