#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool prost1(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i < (int)sqrt(x) + 1; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> ans;
    for (int i = 2; i <= n; i++)
        if (prost1(i))
            for (int j = i; j <= n; j *= i)
                ans.push_back(j);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}