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
unordered_map<int, int> a;
int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            cur++;
        else
            cur--;
        if (!cur)
            ans = i + 1;
        a[cur] = i;
    }
    if (cur == 0)
    {
        cout << n;
        return 0;
    }
    cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            cur++;
        else
            cur--;
        ans = max(ans, a[cur] - i);
    }
    cout << ans;
    return 0;
}