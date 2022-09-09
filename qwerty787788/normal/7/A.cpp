#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;
//
long long n, m;
string s[8];
//
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
		for (int i = 0; i < 8; i++)
			cin >> s[i];
		long long tB = 0;
		for (int i = 0; i < 8; i++) 
			for (int j = 0; j < 8; j++)
				if (s[i][j] == 'B') tB++;
		if (tB == 64) cout << 8 << endl; else {
			long long su = 0;
			for (int i = 0; i < 8; i++) {
				long long tB1 = 0;
				for (int j = 0; j < 8; j++)
					if (s[i][j] == 'B') tB1++;
				if (tB1 == 8) su++;
				tB1 = 0;
				for (int j = 0; j < 8; j++)
					if (s[j][i] == 'B') tB1++;
				if (tB1 == 8) su++;
			}
			cout << su << endl;
		}
}