#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, ans; ios::sync_with_stdio(0), cin >> s;
	for (auto &i : s) {
		while (ans.size() > 0 && ans[ans.size() - 1] < i) ans.pop_back();
		ans.push_back(i);
	}
	cout << ans << endl;
}