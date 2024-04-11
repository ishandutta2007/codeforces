#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define last(X) (X)[(X).size() - 1]
#define last(x, y) (x)[(x).size() - y]
typedef long long ll;
using namespace std;

int k, tot = 0, ans = 0;
string n;
vector<int> dig;

int main() {
	cin >> k >> n;
	for (auto i : n) tot += i - '0', dig.push_back(i - '0');
	sort(dig.begin(), dig.end());
	int j = 0;
	while (tot < k)
		tot += 9 - dig[j++], ans++;
	cout << ans << endl;
}