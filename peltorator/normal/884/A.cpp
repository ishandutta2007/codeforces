#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;

int t = 86400;

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        x -= t - a;
        if (x <= 0)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}