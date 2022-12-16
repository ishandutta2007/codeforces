
//IO
#include <iostream>
#include <cstdio>
#include <iomanip>

//General
#include <cmath>
#include <cstdlib>
#include <cstring>

//STL
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1E9;

int checked[30] = {0};

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	string str;
	cin >> str;
	if (str.size () < 26) {
		cout << -1 << endl;
		return 0;
	}
	int diff = 0, ques = 0;
	for (int i = 0; i < 26; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			if (checked[str[i] - 'A'] == 0) diff++;
			checked[str[i] - 'A']++;
		}
		else
			ques++;
	}
	for (int i = 26; i <= str.size (); i++) {
		if (26 - diff <= ques) {
			int l = 0;
			while (l < 26 && checked[l] > 0) l++;
			for (int j = i - 26; j < i; j++) {
				if (str[j] == '?' && l < 26) {
					str[j] = l + 'A';
					l++;
					while (l < 26 && checked[l] > 0) l++;
				}
			}
			for (int i = 0; i < str.size (); i++)
				if (str[i] == '?') str[i] = 'A';
			cout << str << endl;
			return 0;
		}
		if (i == str.size ()) break;
		if (str[i] >= 'A' && str[i] <= 'Z') {
			if (checked[str[i] - 'A'] == 0) diff++;
			checked[str[i] - 'A']++;
		}
		else
			ques++;
		if (str[i - 26] >= 'A' && str[i - 26] <= 'Z') {
			checked[str[i - 26] - 'A']--;
			if (checked[str[i - 26] - 'A'] == 0) diff--;
		}
		else
			ques--;
//		cout << i << " " << diff << endl;
	}
	cout << -1 << endl;
	return 0;
}