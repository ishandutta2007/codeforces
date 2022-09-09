#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
long long a, c;
//
vector <int> to3(long long a) {
	vector <int> ans;
	while (a != 0) {
		int x = a % 3;
		ans.push_back(x);
		a /= 3;
	}
	return ans;
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> a >> c;
	vector <int> a1 = to3(a);
	vector <int> c1 = to3(c);
	while (a1.size() < c1.size()) a1.push_back(0);
	while (a1.size() > c1.size()) c1.push_back(0);
	vector <int> ans;
	for (int i = 0; i < a1.size(); i++) {
		ans.push_back((c1[i]-a1[i]+3)%3);
	}
	//
	long long ot = 0, um = 1;
	for (int i = 0; i < ans.size(); i++) {
		ot += ans[i]*um;
		um *= 3;
	}
	cout << ot << endl;
}