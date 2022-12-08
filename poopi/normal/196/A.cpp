										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int main(){
	string s1, s2 = "";
	cin >> s1;
	reverse(s1.begin(), s1.end());
	s2 += s1[0];
	for(int i = 1; i < s1.length(); i++)
		if(s2[s2.length() - 1] <= s1[i])
			s2 += s1[i];
	reverse(s2.begin(), s2.end());
	cout << s2 << endl;
	return 0;
}