#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;



int main()
{
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    cout << a[2] - a[0];
    return 0;
}