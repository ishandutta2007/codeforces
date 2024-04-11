#include <map>
#include <iostream>
#include <cstring>
#include <vector>
#include <cctype> 
#include <cstdio>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//
long long n;
vector <string> folders;
string s;
//
void show() {
	cout << "/";
	for (int i = 0; i < folders.size(); i++)
		cout << folders[i] << "/";
	cout << endl;
};
//
int main() {
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "pwd") show(); else {
			cin >> s;
			if (s[0] == '/') {
				folders.clear();
				s = s.substr(1, s.size());
			} 
				string newFolder = "";
				for (int i = 0; i < s.size(); i++) {
					if (s[i] == '/') {
						if (newFolder == "..") folders.pop_back(); else
							folders.push_back(newFolder);
						newFolder = "";
					} else {
						newFolder += s[i];
					}
				}
				if (newFolder == "..") folders.pop_back(); else
					folders.push_back(newFolder);
		}
	}
}