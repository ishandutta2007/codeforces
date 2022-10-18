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

const int N = 200001;

int a[N];
int b[N];
int n, k;

void f(int l, int r)
{
    if (l + 1 == r)
        return;
    if (!k)
        return;
    int mid = (r + l + 1) / 2;
    int j = l;
    int i = mid;
    while (i < r)
    {
        b[j] = a[i];
        i++;
        j++;
    }
    i = l;
    while (i < mid)
    {
        b[j] = a[i];
        i++;
        j++;
    }
    for (int i = l; i < r; i++)
        a[i] = b[i];
    k--;
    mid = (r + l) / 2;
    f(l, mid);
    f(mid, r);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    if (k % 2 == 0)
    {
        cout << -1;
        return 0;
    }  
    for (int i = 0; i < n; i++)
        a[i] = i;
    k = (k - 1) / 2;
    f(0, n);
    if (k)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] + 1 << " ";
    return 0;
}