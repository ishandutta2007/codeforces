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
string s;
int a[100];
int n;
string p[26];
//
int main() {
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //
	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i+n] = p[i];
		reverse(p[i+n].begin(), p[i+n].end());
	}
	for (char c = 'a'; c <= 'z'; c++)
		a[c-'a'] = 0;
	a[s[0]-'a'] = 1;
	for (int i = 1; i < s.size(); i++) {
		int maxi = a[s[i]-'a'];
		for (int c = 'a'; c <= 'z'; c++) {
			string new_="00";
			new_[0] = c;
			new_[1] = s[i];
			bool ok = true;
			for (int j = 0; j < 2 * n; j++)
				if (new_ == p[j])  {
					ok = false;
				}
			if (ok) {
				if (a[c-'a'] + 1 > maxi) maxi = a[c-'a']+1;
			}
		}
		if (maxi > a[s[i]-'a']) a[s[i]-'a'] = maxi;
	}
	int res = s.size();
	for (char c = 'a'; c <= 'z'; c++)
		if (s.size() - a[c-'a'] < res) res = s.size() - a[c-'a'];
	cout << res << endl;

}