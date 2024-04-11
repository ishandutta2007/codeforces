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

int a4, a7, a47, a74;

int main(){
	cin >> a4 >> a7 >> a47 >> a74;
	if(abs(a47 - a74) > 1 || min(a4, a7) < max(a47, a74)){
		cout << -1 << endl;
		return 0;
	}
	string res = "";
	if(a47 == a74){
		if(a4 >= a47 + 1){
			for(int i = 0; i < a4 - a47 - 1; i++)
				cout << 4;
			for(int i = 0; i < a47; i++)
				cout << 47;
			for(int i = 0; i < a7 - a47; i++)
				cout << 7;
			cout << 4 << endl;
		}
		else if(a7 >= a47 + 1){
			for(int i = 0; i < a47; i++)
				cout << 74;
			for(int i = 0; i < a7 - a47; i++)
				cout << 7;
			cout << endl;
		}
		else cout << -1 << endl;
	}
	if(a47 == a74 + 1){
		for(int i = 0; i < a4 - a47; i++)
			cout << 4;
		for(int i = 0; i < a47; i++)
			cout << 47;
		for(int i = 0; i < a7 - a47; i++)
			cout << 7;
		cout << endl;
	}
	if(a47 + 1 == a74){
		cout << 7;
		for(int i = 0; i < a4 - a47 - 1; i++)
			cout << 4;
		for(int i = 0; i < a47; i++)
			cout << 47;
		for(int i = 0; i < a7 - a47 - 1; i++)
			cout << 7;
		cout << 4 << endl;
	}
	return 0;
}