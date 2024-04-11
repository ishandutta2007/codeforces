#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;
//
long long n1, n2;
string s1, s2;
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> s1;
	cin >> s2;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == '4' && s2[i] == '7') n1++; else
			if (s1[i] == '7' && s2[i] == '4') n2++; 
	}

	cout << max(n1, n2) << endl;
	
}