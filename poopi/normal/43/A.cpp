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
	string inp;
	int n;
	while(cin >> n){
		st.clear();
		string s1, s2;
		int mx = 0;
		for(int i = 0; i < n; i++){
			cin >> s1;
			st.insert(s1);
			if(mx < st.count(s1)){
				s2 = s1;
				mx = st.count(s1);
			}
		}
		cout << s2 << endl;
	}
	return 0;
}