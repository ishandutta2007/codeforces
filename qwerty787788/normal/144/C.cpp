#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

string s1, s2;
long long sum = 0;
int need[26];
int now[26];
//
bool ok() {
	for (int i = 0; i < 26; i++) {
		if (now[i] > need[i]) return false;
	}
	return true;
};
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> s1;
	cin >> s2;
	//
	for (int i = 0;i <s2.size(); i++) {
		need[s2[i]-'a']++;
	}
	//
	if (s2.size() > s1.size()) {
		cout << "0" << endl;
	} else {
		int last_i=1;
		for (int i = 0; i < s2.size(); i++) {
			if (s1[i] != '?') now[s1[i]-'a']++;
			last_i = i+1;
		}
		if (ok()) sum++;
		for (int i = last_i; i < s1.size(); i++) {
			if (s1[i-s2.size()] != '?') now[s1[i-s2.size()]-'a']--;
			if (s1[i] != '?') now[s1[i]-'a']++;
			if (ok()) sum++;
		}
		cout << sum << endl;
	}
}