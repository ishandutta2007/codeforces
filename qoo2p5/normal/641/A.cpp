#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <map>
#include <queue>
#pragma comment(linker, "/stack:111")
#define ll long long
#define cs(x) (int)x.size()
#define mp make_pair
#define ld long double
using namespace std;

const int N = 500000;
const ll INF = 1e12;
const ll mod = 10;


int main() {
	//iostream::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	//freopen("kthpath.in", "r", stdin);
	int n;
	cin >> n;
	vector<int> to(n);
	vector<int> len(n);
	string s;
	cin >> s;
	for (int i = 0; i < cs(s); i++) {
		if (s[i] == '<')
			to[i] = -1;
		else
			to[i] = 1;
	}
	for (int i = 0; i < n; i++)
		cin >> len[i];
	vector<bool> visited(n);
	int cur = 0;
	while (!visited[cur]) {
		visited[cur] = 1;
		cur += len[cur] * to[cur];
		if (cur < 0 || cur >= n)
			break;
	}
	if (cur < 0 || cur >= n)
		cout << "FINITE" << endl;
	else
		cout << "INFINITE" << endl;
	return 0;
}