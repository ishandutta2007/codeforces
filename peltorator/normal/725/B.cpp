#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <limits>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	long long n = 0;
	int k;
	cin >> s;
	for (int i = 0; i < s.size() - 1; i++)
        n = n * 10 + (s[i] - '0');
    k = s[s.size() - 1] - 'a';
    long long f = (n - 1) / 4, ans = f * 16;
    int q = n % 4;
    int a[6] = { 5, 4, 3, 0, 1, 2 };
    int qq;
    for (int i = 0; i < 6; i++)
        if (k == a[i])
            qq = i + 1;
    if (q == 2 || q == 0)
        qq += 7;
    cout << ans + qq;
	return 0;
}