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

int a[26];
char b[2][13];

int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s;
	cin >> s;
	int k, l;
	for (int i = 0; i < s.size(); i++)
    {
        if (a[s[i] - 'A'] != 0)
        {
            k = i;
            l = a[s[i] - 'A'] - 1;
        }
        a[s[i] - 'A'] = i + 1;
    }
    if (l + 1 == k)
    {
        cout << "Impossible";
        return 0;
    }
    int n = (k - l - 1) /  2;
    for (int i = l; n >= 0; i++, n--)
        b[1][n] = s[i];
    n = 0;
    for (int i = (k + l - 1) / 2 + 1; i < k; i++, n++)
        b[0][n] = s[i];
    n = (k - l) / 2;
    for (int i = (k + 1) % s.size(); n < 13; i = (i + 1) % s.size(), n++)
        b[0][n] = s[i];
    n = 12;
    for (int i = (14 + (k - l + 1) / 2 + l) % s.size(); n > (k - l - 1) / 2; i = (i + 1) % s.size(), n--)
        b[1][n] = s[i];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 13; j++)
            cout << b[i][j];
        cout << endl;
    }
	return 0;
}