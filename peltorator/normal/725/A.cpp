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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	int i = 0;
	while (i < s.size() &&s[i] == '<')
    {
        i++;
        ans++;
    }
    i = s.size() - 1;
    while (i >= 0 && s[i] == '>')
    {
        i--;
        ans++;
    }
    cout << ans;
	return 0;
}