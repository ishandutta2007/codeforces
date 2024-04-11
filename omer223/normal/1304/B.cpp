#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

bool isPali(string str) {
	if (str.length() == 0) return true;
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - i - 1]) return false;
	}
	return true;
}

int main() {
	unordered_set<string> s;
	vector<string> svec, revs, pali;
	int n, len;
	string str;
	cin >> n >> len;
	for (int i = 0; i < n; i++) {
		cin >> str;
		s.insert(str);
		svec.push_back(str);
	}
	for (string st : svec) {
		if (s.find(st) != s.end()) {
			reverse(st.begin(), st.end());
			if (isPali(st)) {
				pali.push_back(st);
			}
			else if (s.find(st) != s.end()) {
				revs.push_back(st);
				s.erase(st);
				reverse(st.begin(), st.end());
				s.erase(st);
			}
		}
	}
	string res = "", tmpstr;
	if (pali.size() == 0) {
		for (string tt : revs) res += tt;
		tmpstr = res;
		reverse(tmpstr.begin(), tmpstr.end());
		res += tmpstr;
	}
	else {
		for (string tt : revs) res += tt;
		tmpstr = res;
		reverse(tmpstr.begin(), tmpstr.end());
		res += pali[0];
		res += tmpstr;
	}
	cout << res.length() << endl << res << endl;
}