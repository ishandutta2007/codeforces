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

const int N = 300001;
int a[N];
int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int i = 0;
    int ans = 0;
    for (int i = 0; i + k < n; i++)
        ans += a[i];
    ans += k * x;
    cout << ans;
    return 0;
}