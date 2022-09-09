#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>

using namespace std;
//
int n;
string s, s_new;
map <char, int> a;
//
bool prost(int x) {
	if (x == 1) return false;
	int sum = 0;
	for (int i = 1; i*i <= x; i++)
		if (x%i == 0) sum++;
	if (sum > 1) return false; else return true;
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		a[s[i]]++;
	}
	s_new = s;
	for (int i = 0; i < s.size(); i++) {
		s_new[i] = '0';
	}
	//
	bool ev_ok = true;
	for (int i = 2; i <= s.size(); i++) {
		if (prost(i)) {
			int max = 0;
			char best_key = 'a';
			for (char key='a'; key <= 'z'; key++) {
				if (a[key] > max) {
					max = a[key];
					best_key = key;
				}
			}
			//
			char new_key='0';
			for (int j = 1; j*i <=s.size(); j++) {
				if (s_new[j*i-1] != '0') new_key = s_new[j*i-1];
			}
			if (new_key == '0') {
				for (int j = 1; j*i <= s.size(); j++) {
					if (s_new[j*i-1] == '0') {
						s_new[j*i-1] = best_key;
						a[best_key]--;
						if (a[best_key] < 0) ev_ok = false;
					}
				}
			} else {
				for (int j = 1; j*i <= s.size(); j++) {
					if (s_new[j*i-1] == '0') {
						s_new[j*i-1] = new_key;
						a[new_key]--;
						if (a[new_key] < 0) ev_ok = false;
					}
				}
			}
			//
		}
	}
	//
	if (!ev_ok) cout << "NO" << endl; else {
		cout << "YES"<< endl;
		for (char key='a'; key <= 'z'; key++) {
				if (a[key] > 0) {
					s_new[0] = key;
				}
			}
		//
		cout << s_new << endl;
	}
	//
	return 0;
}