#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;
#define PI 3.1415926535897932384626433832795
//
int N;
vector <string> a;
vector <int> big;
vector <int> mark;
string s;
string t;
//

//
int main() {
	//cout.precision(1);
	//freopen("input.txt", "r", stdin);
	cin >> N;
	string s1;
	for (int i = 0; i < N; i++) {
		cin >> s1;
		a.push_back(s1);
	}
	cin >> s;
	cin >> t;
	//
	for (int i =0; i< s.size(); i++) {
		string s1 = s.substr(i, 1);
		if (s1[0] <= 'Z') {
			big.push_back(1);
		} else {
			big.push_back(0);
		}
	}
	//
	for (int i = 0; i < s.length(); i++)
		mark.push_back(0);
	//
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	for (int i = 0; i < N; i++)
		transform(a[i].begin(), a[i].end(), a[i].begin(),  ::tolower);
	for (int i = 0; i < N; i++) {
		int start = 0;
		while (s.substr(start).find(a[i]) != -1) {
			start += s.substr(start).find(a[i]) + 1;
			for (int j = start-1; j <= start+a[i].length()-2; j++)
				mark[j] = 1;
		}
	}
	//
	string answ;
	for (int i = 0; i < s.length(); i++) {
		if (mark[i] == 0) answ.append(s.substr(i, 1)); else {
			if (s.substr(i, 1) == t) {
				if (t == "a") answ.append("b"); else
							  answ.append("a");
			} else {
				answ.append(t);
			}
		}
	}
	//
	for (int i = 0; i < answ.length(); i++) {
		if (big[i]) {
			string s1 = answ.substr(i, 1);
			transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
			string s2 = answ.substr(0, i);
			s2.append(s1);
			if (i+1 < answ.length()) s2.append(answ.substr(i+1));
			answ = s2;
		}
	}
	//
	cout << answ << endl;
	//
	return 0;
}