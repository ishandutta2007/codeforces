				/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

set <int> st;

int main(){
	for(int i = 1; i < 100; i++)
		st.insert(i * (i + 1) / 2);
	int n;
	while(cin >> n)
		cout << (st.count(n) ? "YES" : "NO") << endl;
	return 0;
}