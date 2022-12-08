				/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

multiset <string> st;

int main(){
	string s1, s2;
	int n;
	while(cin >> s1 >> s2){
		reverse(s1.begin(), s1.end());
		cout << (s1 == s2 ? "YES" : "NO") << endl;
	}
	return 0;
}