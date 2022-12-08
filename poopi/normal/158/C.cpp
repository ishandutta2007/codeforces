										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n;
vector <string> v;

int main(){
	cin >> n;
	string cmd;
	for(int I = 0; I < n; I++){
		cin >> cmd;
		if(cmd == "pwd"){
			cout << '/';
			for(int i = 0; i < v.size(); i++)
				cout << v[i] << '/';
			cout << endl;
			continue;
		}
		string str, dr;
		cin >> str;
		if(str[0] == '/')
			v.clear();
		for(int i = 0; i < str.length(); i++)
			if(str[i] == '/')
				str[i] = ' ';
		istringstream sin(str);
		while(sin >> dr){
			if(dr == "..")
				v.pop_back();
			else v.push_back(dr);
		}
	}
	return 0;
}