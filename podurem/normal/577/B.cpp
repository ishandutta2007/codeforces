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

typedef long long ll;

bool vis[1010][1010][2];
int n, m;
vector <int> a;

bool go(int i, int sum, bool t) 
{
    if (i == n) 
        return !sum && t;
    if (vis[i][sum][t]) 
        return 0;
    vis[i][sum][t] = 1;
    return go(i + 1, sum, t) || go(i + 1, (sum + a[i]) % m, 1);
}

int main() 
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n > m || go(0, 0, 0)) 
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}