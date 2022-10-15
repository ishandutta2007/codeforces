//============================================================================
// Name        : 544A.cpp
// Author      : Daxi the Taxi
// Version     :
// Copyright   : ALL YOUR CODE IS BELONG TO US
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int am, bm;
string a, b;

inline void toMinutes(string &s, int &i){
//	printf("%s %s %s\n", s.c_str(), s.substr(0, 2).c_str(), s.substr(2, 2).c_str());
	i = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

inline void printTime(int mins){
	printf("%02d:%02d\n", mins / 60, mins % 60);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	toMinutes(a, am);
	toMinutes(b, bm);

	printTime(am + ((bm - am) >> 1));
}