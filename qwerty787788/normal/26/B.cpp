#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;
//
long long n;
string s;
//
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
        cin >> s;
		n = s.size();
		long long now = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') now++; else
				if (now > 0) now--; else n--;
		}
		n -= now;
		cout << n;
		
}