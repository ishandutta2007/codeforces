				/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

set <string> st;

int main(){
	string inp;
	int n;
	while(cin >> n){
		string s1, s2;
		for(int i = 0; i < n; i++){
			cin >> s1 >> s2;
			st.insert(s1+s2);
		}
		cout << st.size() << endl;
	}
	return 0;
}