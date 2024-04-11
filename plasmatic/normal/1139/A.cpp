//============================================================================
// Name        : 548A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
string s;
ll tot = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; ++i) {
		if(s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8')
			tot += i + 1;
	}

	cout << tot << endl;
}