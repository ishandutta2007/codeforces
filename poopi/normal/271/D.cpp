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
#include <set>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define B 43

int k;
string str, bl;
set <int64> st;

int main(){
	cin >> str >> bl >> k;
	for(int i = 0; i < str.length(); i++){
		int64 h = 1, cnt = 0;
		for(int j = i; j < str.length(); j++){
			if(bl[str[j] - 'a'] == '0'){
				cnt++;
				if(cnt > k)
					break;
			}
			h = h * B + (int)(str[j] - 'a');
			st.insert(h);
		}
	}
	cout << st.size() << endl;
	return 0;
}