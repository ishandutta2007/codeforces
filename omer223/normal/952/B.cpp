#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set<string> reg{"no","don't think so","great","not bad", "don't touch me", "cool"}, 
grumpy{"no","don't even","are you serious", "go die in a hole","worse", "no way", "terrible"};

string ask(int x) {
	cout << x << endl;
	fflush(stdout);
	string ans;
	getline(cin, ans);
	return ans;
}

int main() {
	fast;
	foru(i, 0, 10) {
		string x = ask(i);
		if (reg.count(x) ^ grumpy.count(x)) {
			if (reg.count(x))cout << "normal" << endl;
			else cout << "grumpy" << endl;
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}