										/* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, double>

string str;

int main(){
	getline(cin, str);
	for(int i = 0; i < str.length(); i++){
		while(i < str.length() && str[i] == ' ')
			i++;
		if(i == str.length()) break;
		string tmp = "";
		if(str[i] == '"'){
			while(str[++i] != '"')
				tmp += str[i];
		}
		else while(i < str.length() && str[i] != ' ')
				tmp += str[i++];
		cout << '<' << tmp << '>' << endl;
	}
	return 0;
}